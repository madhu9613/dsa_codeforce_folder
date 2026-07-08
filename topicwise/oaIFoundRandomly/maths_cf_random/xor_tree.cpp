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
int a[MAXN];
int b[MAXN];
vi ans;

void dfs(int u,int p,int even,int odd,int d){
    int c_val=a[u];
    if(d%2==0){
        c_val^=even;
    }else{
        c_val^=odd;
    }

    if(c_val!=b[u]){
        ans.push_back(u);
        if(d%2==0){
            even^=1;
        }else{
            odd^=1;
        }
    }

    for(int v:adj[u]){
        if(v==p) continue;
        dfs(v,u,even,odd,d+1);
    }
}
void solve() {
    int n;
    cin>>n;
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];

    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    dfs(1,0,0,0,1);
    cout<<ans.size()<<endl;
    for(int x:ans){
        cout<<x<<endl;
    }
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