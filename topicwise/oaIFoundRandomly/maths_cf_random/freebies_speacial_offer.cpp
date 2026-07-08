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

void solve() {
    int n,m,k;cin>>n>>m>>k;
    vll a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(all(a));
    a.resize(k);

    vll pref(k+1,0);
    for(int i=1;i<=k;i++){
        pref[i]=pref[i-1]+a[i-1];
    }
    vi best(k+1,0);
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        if(x<=k){
            best[x]=max(best[x],y);
        }
    }

    // dp[i]= min cost to buy exectly first i item;
    vll dp(k+1,INF);
    dp[0]=0;
    for(int i=1;i<=k;i++){
        for(int j=1;j<=i;j++){
            int free=best[j];

            ll paid=pref[i]-pref[i-j+free];
            dp[i]=min(dp[i],dp[i-j]+paid);
        }
    }
    cout<<dp[k]<<endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}