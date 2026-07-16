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

void solve() {

    int n,k;cin>>n>>k;
    vi a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
sort(a.begin()+1,a.end());
vector<vi>dp(n+1,vi(k+1,0));
for(int i=1;i<=n;i++){
    auto it=lower_bound(a.begin()+1,a.end(),a[i]-5);
    int tstart=distance(a.begin(),it);
    int team_sz=i-tstart+1;
    for(int j=1;j<=k;j++){
        dp[i][j]=dp[i-1][j];
        dp[i][j]=max(dp[i][j],dp[tstart-1][j-1]+team_sz);
    }
    
}

cout<<dp[n][k]<<endl;
    
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