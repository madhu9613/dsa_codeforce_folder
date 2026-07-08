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

void solve() {
 // dp[0]=subseq end with neg value;
 // dp[1]=end with a +ve value;
 //s[0]=max sum when len is max adn end with nega
 // s[1];;
 
 int n;
 cin>>n;
 vll a(n+1);
 for(int i=1;i<=n;i++){
    cin>>a[i];
 }
 ll dp0=0,dp1=0,s0=0,s1=0;
 for(int i=1;i<=n;i++){
    if(a[i]>0){
       int ndp1=dp0+1; 
       if(ndp1==dp1){
        s1=max(s1,s0+a[i]);
       }
       else{
        dp1=ndp1;
        s1=s0+a[i];
       }
    }
    else{
        int ndp0=dp1+1;
        if(ndp0==dp0){
            s0=max(s0,s1+a[i]);
        }
        else{
            dp0=ndp0;
            s0=s1+a[i];
        }
    }
 }

 if(dp0>dp1){
    cout<<s0<<endl;
 }
 else if(dp0<dp1){
    cout<<s1<<endl;
 }else{
    cout<<max(s0,s1)<<endl;
 }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
   // precompute();
   // freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}