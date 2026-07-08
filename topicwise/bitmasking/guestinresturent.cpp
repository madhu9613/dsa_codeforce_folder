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
    int n;cin>>n;
    vi a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];

    }
    int p;cin>>p;
    vector<double>fact(n+1,1);
    for(int i=1;i<=n;i++){
        fact[i]=fact[i-1]*i;
    }
    double ans=0;
    for(int i=0;i<n;i++){
        vector<vector<double>>dp(n+1,vector<double>(p+1,0));
        dp[0][0]=1;
        for(int j=0;j<n;j++){
            if(j==i){
                continue;

            }
            for(int k=n;k>=1;k--){
                for(int s=p;s>=a[j];s--){
                    dp[k][s]+=dp[k-1][s-a[j]];
                }
            }
        }

    double prob=0;
    for(int k=0;k<n;k++){
        for(int s=0;s<=p;s++){
            if(s+a[i]<=p){
                prob+=dp[k][s]*fact[k]*fact[n-k-1];
            }
        }
    }

    prob/=fact[n];
    ans+=prob;

    }
    cout<<fixed<<setprecision(10)<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}