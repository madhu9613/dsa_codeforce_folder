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
    vi h(n);
    int mxpos=0;
    for(int i=0;i<n;i++){
        cin>>h[i];
        if(h[i]>h[mxpos]){
            mxpos=i;
        }
    }
    vi a(n+1);
    for(int i=0;i<n;i++){
        a[i]=h[(mxpos+i)%n];
    }
    a[n]=a[0];
    int m=n+1;
    vi L(m,-1);
    vi R(m,m);
    vi C(m,0);
    for(int i=1;i<n;i++){
        L[i]=i-1;
        while(L[i]>0 && a[i]>=a[L[i]]){
            L[i]=L[L[i]];
        }
    }

    for(int i=n-1;i>=0;i--){
        R[i]=i+1;
        while(R[i]<n && a[i]>a[R[i]]){
            R[i]=R[R[i]];

        }
        if(R[i]<n && a[i]==a[R[i]]){
            C[i]=C[R[i]]+1;
            R[i]=R[R[i]];
        }
    }
    ll ans=0;
    for(int i=1;i<n;i++){
        ans+=2;
        ans+=C[i];
        if(L[i]==0 && R[i]==n){
            ans--;
        }
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