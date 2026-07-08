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
    vll a(n+1);
    vll pref(n+1);
    pref[0]=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    pref[i]=pref[i-1]+a[i];
    }
    vi p(n);
    for(int i=0;i<n;i++){
        cin>>p[i];
    }
    vi L(n+2),R(n+2);
    for(int i=1;i<=n;i++){
        L[i]=i;
        R[i]=i;
    }
    vector<bool>active(n+2,false);
    vll ans;
    ll cmax=0;
    for(int i=n-1;i>=0;i--){
        ans.push_back(cmax);
        int x=p[i];
        active[x]=true;
        int left=active[x-1]?L[x-1]:x;
        int right=active[x+1]?R[x+1]:x;

        R[left]=right;
        L[right]=left;
        ll nssum=pref[right]-pref[left-1];
        cmax=max(cmax,nssum);
    }
    reverse(all(ans));
    for(ll x:ans){

        cout<<x<<endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}