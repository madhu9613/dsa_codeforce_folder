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

ll f(ll a,ll b,ll c,ll d,int k){
    if(a>b || c>d){
        return 0;
    }
    ll len=1ll<<k;
    while(true){
        bool chang=false;
        while(a>len){
            a-=len;
            b-=len;
            chang=true;
        }
        while(c>len){
            c-=len;
            d-=len;
            chang=true;
        }

        while(len>max(b,d)){
            k--;
            len>>=1;
            chang=true;
        }

        if(a>c || (a==c && b>d)){
            swap(a,c);
            swap(b,d);
            chang=true;
        }
        if(!chang){
            break;
        }
    }

    if(b>=d){
        return d-c+1;
    }
    ll ans=0;
    ans=max(ans,f(a,b,c,len-1,k));
    ans=max(ans,f(1,d-len,a,b,k));
    ans=max(ans,b-c+1);
    return ans;

}
void solve() {

    ll l1,r1,l2,r2;
    cin>>l1>>r1>>l2>>r2;
    cout<<f(l1,r1,l2,r2,30)<<endl;
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) solve();

    return 0;
}