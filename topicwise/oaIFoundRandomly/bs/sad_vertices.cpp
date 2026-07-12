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
const int MAXN = 2e5 + 5;

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

int n;
ll a[MAXN];
vector<pair<int,ll>>adj[MAXN];
int sz[MAXN];
ll ans=0;

void dfs1(int u){
    sz[u]=1;
    for(auto &[v,w]:adj[u]){
        dfs1(v);
        sz[u]+=sz[v];
    }
}

void dfs2(int u,ll dist,ll mn){
    if(dist-mn>a[u]){
        ans+=sz[u];
        return;
    }
    mn=min(mn,dist);
    for(auto &[v,w]:adj[u]){
        dfs2(v,dist+w,mn);
    }

}
void solve() {

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=2;i<=n;i++){
        int p;
        ll c;
        cin>>p>>c;
        adj[p].push_back({i,c});
    }

    dfs1(1);
    dfs2(1,0,0);
    cout<<ans<<endl;

    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
   // precompute();
   // freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);
    int t = 1;
    while (t--) solve();
    return 0;
}