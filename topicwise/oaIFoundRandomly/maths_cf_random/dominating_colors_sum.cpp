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

vi adj[MAXN];
int color[MAXN],heavy[MAXN];
ll ans[MAXN];
ll freq[MAXN];  // cnt of each color
ll csum=0;
int max_f=0;

int dfs1(int u,int p){
    int sz=1;
   int max_child=0;
   for(int v:adj[u]){
    if(v==p) continue;
    int child=dfs1(v,u);
    sz+=child;
    if(child>max_child){
        max_child=child;
        heavy[u]=v;
    }
   }
   return sz;
}

void upd(int u,int p,int val,int H)
{
    int c=color[u];
    freq[c]+=val;
    if(freq[c]>max_f){
        max_f=freq[c];
        csum=c;
    }
    else if(freq[c]==max_f){
        csum+=c;
    }
    for(int v:adj[u]){
        if(v==p || v==H) continue;
        upd(v,u,val,H);
    }
}
void dfs2(int u,int p,bool keep){
  for(int v:adj[u]){
    if(v!=p && v!=heavy[u]){
        dfs2(v,u,false);
    }
  }

  if(heavy[u]){
    dfs2(heavy[u],u,true);
  }
  upd(u,p,1,heavy[u]);
  ans[u]=csum;
  if(!keep){
    upd(u,p,-1,0);
    max_f=0;
    csum=0;
  }
}

void solve() {

    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>color[i];
    }
    for(int i=0;i<n-1;i++){
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs1(1,0);
    dfs2(1,0,true);
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
   // precompute();
    int t = 1;
    while (t--) solve();
    return 0;
}