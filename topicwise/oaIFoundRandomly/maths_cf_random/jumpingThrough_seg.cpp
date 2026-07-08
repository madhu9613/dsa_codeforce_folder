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
    vector<pair<ll,ll>>segs(n);
    for(int i=0;i<n;i++){
        ll l,r;
        cin>>l>>r;
        segs[i]={l,r};
    }
    

    auto can=[&](ll k)->bool{
        ll low=0,high=0;
        for(auto &[l,r]:segs){

            low-=k;
            low=max(low,l);
            high+=k;
            high=min(high,r);

            if(low>high) return false;

        }

        return true;

    };
    ll ans=-1;
    ll l=0,r=1e9;
    while(l<=r){
        ll m=(l+r)/2;
        if(can(m)){
            ans=m;
            r=m-1;
        }else{
            l=m+1;
        }
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