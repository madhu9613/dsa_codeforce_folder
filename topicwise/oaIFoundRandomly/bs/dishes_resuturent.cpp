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
    int n;
    cin>>n;
    vll a(n);
    vll b(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    ll R=0;
    for(int i=0;i<n;i++){
        cin>>b[i];
        R+=b[i];
    }

    ll ans=0;

    ll L=1;

    auto can=[&](ll x)->bool{
        ll by_me=x;
        bool isokay=true;
        for(int i=0;i<n;i++){
            if(a[i]<=x){
                // okay i will use couries;
            }
            else{
                if(by_me>=b[i]){
                    by_me-=b[i];
                }
                else{
                    isokay=false;
                    break;
                }
            }
        }
        return isokay;

    };
    while(L<=R){
        ll mid=L+(R-L)/2;
        if(can(mid)){

            ans=mid;
            R=mid-1;

        }
        else{
            L=mid+1;

        }
    }

    cout<<ans<<endl;

    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
   // precompute();
   // freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}