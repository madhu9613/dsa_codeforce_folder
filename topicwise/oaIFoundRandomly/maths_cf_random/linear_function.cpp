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

using matrix =vector<vll>;
matrix mul(matrix m1,matrix m2){
    matrix res(2,vll(2,0));
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            for(int k=0;k<2;k++){
                res[i][j]=(res[i][j]+m1[i][k]*m2[k][j])%MOD;
            }
        }
    }
    return res;
}

matrix m_pow(matrix A,ll p){
    matrix res={{1,0},{0,1}};
    while(p>0){
        if(p%2) res=mul(res,A);
        A=mul(A,A);
        p/=2;
    }
    return res;
}

void solve() {
    ll A,B,n,x;cin>>A>>B>>n>>x;
    matrix T={{A%MOD,B%MOD},{0,1}};

    matrix Tn=m_pow(T,n);
    ll ans=(Tn[0][0]*x%MOD)%MOD;
    ans=(ans+Tn[0][1])%MOD;

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