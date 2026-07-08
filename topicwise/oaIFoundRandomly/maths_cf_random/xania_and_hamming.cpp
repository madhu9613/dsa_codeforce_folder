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
    ll n,m;cin>>n>>m;
    string x,y;cin>>x>>y;
    ll lx=x.length();
    ll ly=y.length();
    ll g=gcd(lx,ly);
    ll l=lcm(lx,ly);
    ll total_len=n*lx;
    ll blocks=total_len/l;
    vector<vi>xcnt(g,vi(26,0));
    for(int i=0;i<lx;i++){
        xcnt[i%g][x[i]-'a']++;
    }
    ll matches=0;
    for(int j=0;j<ly;j++){
        int rem=j%g;
        int tchar=y[j]-'a';
        matches+=xcnt[rem][tchar];
    }
    ll total_matches=matches*blocks;
    cout<<total_len-total_matches<<endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
   
    while (t--) solve();

    return 0;
}