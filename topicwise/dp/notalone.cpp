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

ll f(vll &a){
    int n=a.size();
    vll dp(n+1,LLONG_MAX);
    dp[0]=0;
    for(int i=1;i<=n;i++){
        if(i>=2 && dp[i-2]!=LLONG_MAX){
            dp[i]=min(dp[i],dp[i-2]+abs(a[i-2]-a[i-1]));
        }

        if(i>=3 && dp[i-3]!=LLONG_MAX){
            vll v={a[i-3],a[i-2],a[i-1]};
            sort(all(v));
            ll med=v[1];
            ll cost=abs(v[0]-med)+abs(v[1]-med)+abs(v[2]-med);
            dp[i]=min(dp[i],dp[i-3]+cost);
        }
    }
    return dp[n];
}

void solve() {


 int n;cin>>n;
 vll a(n);
 for(int i=0;i<n;i++){
    cin>>a[i];
 }   
 ll ans=LLONG_MAX;
 for(int i=0;i<3;i++){
    vll b;
    for(int j=0;j<n;j++){
        b.push_back(a[(i+j)%n]);
    }
    ans=min(ans,f(b));
 }

 cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}