#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
#define vi vector<int>
#define vll vector<ll>
#define vpi vector<pii>
#define vpll vector<pll>

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

const ll INF = 1e18;
const int MOD = 1000000007;
const int MAXN = 500005;

ll modpow(ll a, ll b, ll mod = MOD) {
    ll res = 1;
    a %= mod;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

ll modinv(ll a, ll mod = MOD) {
    return modpow(a, mod - 2, mod);
}

ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}
vi adj[MAXN];
int depth[MAXN],heavy[MAXN];
string s;
vector<pair<int,int>>queries[MAXN];
bool ans[MAXN];
int Mask_at_depth[MAXN];
int dfs1(int u,int p,int d){
    int sz=1;
    depth[u]=d;
    int max_child=0;
    for(int v:adj[u]){

        if(v==p) continue;
        int child=dfs1(v,u,d+1);
        sz+=child;
        if(child>max_child){
            max_child=child;
            heavy[u]=v;
        }

    }
    return sz;
}

void upd(int u,int p,int H){
    // we are dealing with toggleing maskl
    Mask_at_depth[depth[u]]^=(1<<(s[u]-'a'));
    for(int v:adj[u]){
        if(v==p || v==H) continue;
        upd(v,u,H);
    }

}

void dfs2(int u,int p,bool keep){
    for(int v:adj[u]){
        if(v==p || v==heavy[u]) continue;
        dfs2(v,u,false); // light node;
    }
    if(heavy[u]!=0){
        dfs2(heavy[u],u,true);
    }
    upd(u,p,heavy[u]);
    for(auto &q:queries[u]){
        // of all node u query;
        int h=q.first;
        int id=q.second;
        int mask=Mask_at_depth[h];
        if(mask==0 || (mask&(mask-1))==0){
            ans[id]=true;
        }else{
            ans[id]=false;
        }
    }

    if(!keep){
        upd(u,p,-1);
    }

}
void solve() {
    int n,m;cin>>n>>m;
    for(int i=2;i<=n;i++){
        int p;cin>>p;
        adj[p].push_back(i);
        adj[i].push_back(p);
    }
    cin>>s;
    s=" "+s;
    for(int i=0;i<m;i++){
        int v,h;
        cin>>v>>h;
        queries[v].push_back({h,i});
    }
    dfs1(1,0,1);
    dfs2(1,0,true);
    for(int i=0;i<m;i++){
        if(ans[i]){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
   // precompute();
    int t = 1;
    while (t--) solve();
    return 0;
}