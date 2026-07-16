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

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

void solve() {

    int n,k;
    cin>>n>>k;
    vi a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    //  f(a)->max cons. ones in a;
    // 
    int ansl=0;
    int ansr=-1;
    int l=0;
    int missed=0;
    int maxlen=0;
    for(int r=0;r<n;r++){
        if(a[r]!=1){
            missed++;
        }
        while(missed>k){
            if(a[l]==0){
                missed--;
            }
            l++;
        }
        int cl=r-l+1;
        if(cl>maxlen){
            maxlen=cl;
            ansl=l;
            ansr=r;
        }
    }

    cout<<maxlen<<endl;
    for(int i=0;i<ansl;i++){
        cout<<a[i]<<" ";
    }
    for(int i=ansl;i<=ansr;i++){
        cout<<1<<" ";
    }
    for(int i=ansr+1;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
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