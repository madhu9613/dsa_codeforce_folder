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

/**

okay how the magic 1/d;
the trees path are independent i mean i am going on path 
1->a->b->c->(node i) 
its does not affect different path;
till here node(i) to be expecitlhy chosen i have d option 
so its 1/d;
let xi =1 if its explicitly chosen
    xi=0 if its removed due to some ancestor;

    so total steps;
    s=x1+x2+x3+x4....
    so E(S)=sigma(E[xi])
    and E[xi]=prob to chose node i expecitly its 1/d
*/

vector<vector<int>> adj;

double ans=0.0;
void dfs(int u,int p,int d){
    
     ans+=1.0/d;
    for(int v:adj[u]){
        if(v==p) continue;
        dfs(v,u,d+1);
    }
}
void solve() {
    int n;cin>>n;
    adj.resize(n+1);
    for(int i=1;i<n;i++){
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1,0,1);
    cout<<fixed<<setprecision(20)<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}