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
    vector<vector<double>>prob(n,vector<double>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>prob[i][j]; //prob that i beat j;
        }
    }

    int FULL=(1<<n)-1;
    vector<vector<double>>dp(FULL+1,vector<double>(n,0.0));

    dp[1<<0][0]=1.0; // if {00001} winner is me and i wnat this so its 1.0;
for(int mask=1;mask<=FULL;mask++){

    if(__builtin_popcountll(mask)<=1) continue;
    for(int c=0;c<n;c++){
        //c is current champion so he must alive ;
        if(!(mask & 1<<c)) continue;
        for(int x=0;x<n;x++){
            // x comes for a fight ; 
            if(c==x || !(mask & 1<<x)) continue; // for fight x must not be c or he must be alive;
            double winc=prob[c][x]*(dp[mask^(1<<x)][c]);
            double winx=prob[x][c]*(dp[mask^(1<<c)][x]);
            dp[mask][c]=max(dp[mask][c],(winc+winx));
        }

    }
}

    double ans=0.0;
    for(int c=0;c<n;c++)
    {
        ans=max(ans,dp[FULL][c]);
    }
    cout << fixed << setprecision(10) << ans << "\n";

   

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}