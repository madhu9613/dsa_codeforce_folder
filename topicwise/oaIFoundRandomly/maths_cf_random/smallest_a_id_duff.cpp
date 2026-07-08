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
const int MAXN = 1e5 + 5;

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

const int LOG=20;
vi adj[MAXN];
vi people[MAXN]; // people living in ith city{there ids}
int up[MAXN][LOG];
int depth[MAXN];
vi best[MAXN][LOG];

vi merge(const vi &a, const vi &b)
{
    vi res;
    int i = 0, j = 0;
    while (i < a.size() && j < b.size() && res.size() < 10)
    {
        if (a[i] < b[j])
        { 
            res.push_back(a[i++]);
        }
        else
        {
            res.push_back(b[j++]);
        }
    }
    while (i < a.size() && res.size() < 10)
    {
        res.push_back(a[i++]);
    }
    while (j < b.size() && res.size() < 10)
    {
        res.push_back(b[j++]);
    }
    return res;
}
void dfs(int u,int p,int d){
    up[u][0]=p;
    depth[u]=d;
    best[u][0]=people[u];
    for(int j=1;j<LOG;j++){
        up[u][j]=up[up[u][j-1]][j-1];
        best[u][j]=merge(best[u][j-1],best[up[u][j-1]][j-1]);
    }
    for(int v:adj[u]){
        if(v!=p){
            dfs(v,u,d+1);
        }
    }
}


void solve() {
 int n,m,q;
 cin>>n>>m>>q;
 for(int i=0;i<n-1;i++){
    int u,v;
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
 }
 for(int i=1;i<=m;i++){
    int c;cin>>c;
    people[c].push_back(i);
 }
 for(int i=1;i<=n;i++){
    if(!people[i].empty()){
        sort(all(people[i]));
    }
    if(people[i].size()>10){
        people[i].resize(10);
    }
 }

 dfs(1,1,0);
 while(q--){
    int u,v,a;
    cin>>u>>v>>a;
    vi res;
    if(depth[u]<depth[v]){
        swap(u,v);
    }
    int diff=depth[u]-depth[v];
    for(int j=0;j<LOG;j++){
        if((diff>>j)&1){

            res=merge(res,best[u][j]);
            u=up[u][j];
        }
    }
    if(u==v){
        res=merge(res,best[u][0]); // including lca;
    }
    else{
        for(int j=LOG-1;j>=0;j--){
            if(up[u][j]!=up[v][j]){
                res=merge(res,best[u][j]);
                res=merge(res,best[v][j]);
                u=up[u][j];
                v=up[v][j];
            }
        }
        res=merge(res,best[u][0]);
        res=merge(res,best[v][0]);
        res=merge(res,best[up[u][0]][0]); // lca;
    }

    int k=min((int)res.size(),a);
    cout<<k<<" ";
    for(int j=0;j<k;j++){
        cout<<res[j]<<" ";
    }
    cout<<endl;
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