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

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

const int MAXN=1005;
ll a[MAXN][MAXN];
ll pref1[MAXN][MAXN]; //(1,1) to (i,j)
ll pref2[MAXN][MAXN] ; //(n,1) to (i,j);

ll suff1[MAXN][MAXN]; // (i,j) to (n,m);
ll suff2[MAXN][MAXN]; //(i,j) to (1,m);



void solve() {

    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            pref1[i][j]=a[i][j]+max(pref1[i-1][j],pref1[i][j-1]);

        }
    }

    for(int i=n;i>=1;i--){
        for(int j=1;j<=m;j++){
            pref2[i][j]=a[i][j]+max(pref2[i+1][j],pref2[i][j-1]);
        }
    }

    for(int i=n;i>=1;i--){
        for(int j=m;j>=1;j--){
            suff1[i][j]=a[i][j]+max(suff1[i+1][j],suff1[i][j+1]);
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=m;j>=1;j--){
            suff2[i][j]=a[i][j]+max(suff2[i-1][j],suff2[i][j+1]);
        }
    }

    ll max_gain=0;
    for(int i=2;i<n;i++){
        for(int j=2;j<m;j++){
            ll op1=pref1[i][j-1]+suff1[i][j+1]+pref2[i+1][j]+suff2[i-1][j];

            ll op2=pref1[i-1][j]+suff1[i+1][j]+pref2[i][j-1]+suff2[i][j+1];
            max_gain=max({max_gain,op1,op2});
        }
    }

    cout<<max_gain<<endl;


    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
   // precompute();
   // freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);
    int t = 1;
    while (t--) solve();
    return 0;
}