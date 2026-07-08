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

// Fast exponentiation (a^b % mod)
ll modpow(ll a, ll b, ll mod = MOD) {
    ll res = 1;
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

// GCD
ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

// LCM
ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}


vector<vector<int>>adj;
vi dp,val,res;

void dfs1(int u,int p=-1){
    dp[u]=val[u];

    for(int v:adj[u]){
        if(v==p) continue;
        dfs1(v,u);
        dp[u]+=max(0,dp[v]);
    }
}

void dfs2(int u, int p = -1)
{
    for (int v : adj[u])
    {
        if (v == p)
            continue;

      
        int par_val = max(0, res[u] - max(0, dp[v]));

        res[v] = dp[v] + par_val;

        dfs2(v, u);
    }
}
void solve() {

    int n;cin>>n;
    val.resize(n+1);
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        if(x==0){
            x=-1;
        }
        val[i]=x;
    }
    adj.resize(n+1);
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dp.resize(n+1);
    res.resize(n+1);

    dfs1(1);
    res[1]=dp[1];
    dfs2(1);

    for(int i=1;i<=n;i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;
    

    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}