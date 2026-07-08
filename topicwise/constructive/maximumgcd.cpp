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
 int n,k;cin>>n>>k;
 vi a(n),cnt(n+1,0);
 for(int i=0;i<n;i++){
    cin>>a[i];
    cnt[a[i]]++;
 }   
 vi pref(n+1,0);
 for(int i=1;i<=n;i++){
    pref[i]=pref[i-1]+cnt[i];
 }
 for(int d=n;d>=1;d--){
    int lim=min(n,4*d-1);
    int under=pref[lim];
    int mul=0;
    for(int j=1;j<=3;j++){
        if(j*d<=n){
            mul+=cnt[j*d];
        }
    }

    int badcnt=under-mul;
    if(badcnt<=k){
        cout<<d<<endl;
        return;
    }
 }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}