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
    
    string s1,s2;cin>>s1>>s2;
    if(s1+s2!=s2+s1){
        cout<<0<<endl;
        return;
    }
    int n=s1.size();
    int m=s2.size();
    int g=gcd(n,m);
    int ans=0;
    for(int len=1;len<=g;len++){
        if(g%len!=0) continue;
        string d=s1.substr(0,len);
        bool ok=true;
        for(int i=0;i<n;i++){
            if(s1[i]!=d[i%len]){
                ok=false;
                break;
            }
        }

        for(int i=0;i<m;i++){
            if(s2[i]!=d[i%len]){
                ok=false;
                break;
            }
        }
        if(ok){
            ans++;
        }
    }
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    
    while (t--) solve();

    return 0;
}