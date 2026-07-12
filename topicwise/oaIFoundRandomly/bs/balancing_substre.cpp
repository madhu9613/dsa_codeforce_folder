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
const int MAXN = 40000;

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
int cnt=0;
int dfs(int u){
   
    int bal=0;
    for(int v:adj[u]){

        bal+=dfs(v);
    }
   if(a[u]+bal==0){
    cnt++;
   }
   return a[u]+bal;
}


void solve() {
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        adj[i].clear();
        a[i]=0;
    }
    for(int i=2;i<=n;i++){
        int p;
        cin>>p;
        adj[p].push_back(i);
    }
    string s;
    cin>>s;
    s=" "+s;
    cnt=0;
    for(int i=1;i<=n;i++){
        a[i]=(s[i]=='B')?1:-1;
    }
    dfs(1);
    cout<<cnt<<endl;
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
   // precompute();
   // freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);
    int t = 1;
    cin>>t;
    while (t--) solve();
    return 0;
}