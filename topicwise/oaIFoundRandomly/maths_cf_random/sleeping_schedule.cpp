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
// i have to optn chose a[i] or a[i]-1; for 
int n,h,l,r;
cin>>n>>h>>l>>r;

vi a(n);
for(int i=0;i<n;i++){
    cin>>a[i];
}

auto is_good=[&](int t)->int{

    if(t>=l && t<=r){
        return 1;
    }
    return 0;

};

vector<vector<int>>dp(n+1,vector<int>(h,-1));
dp[0][0]=0;

for(int i=0;i<n;i++){
    for(int j=0;j<h;j++){

        if(dp[i][j]==-1) continue;


        // chose ai
        int t1=(j+a[i])%h;
        dp[i+1][t1]=max(dp[i+1][t1],dp[i][j]+is_good(t1));

        // chose ai-1;

        int t2=(j+a[i]-1)%h;
        dp[i+1][t2]=max(dp[i+1][t2],dp[i][j]+is_good(t2));
    }
}
int ans=0;
for(int j=0;j<h;j++){
    ans=max(ans,dp[n][j]);
}

cout<<ans<<endl;



    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}