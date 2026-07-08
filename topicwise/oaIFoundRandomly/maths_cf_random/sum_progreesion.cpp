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
    int n,q;cin>>n>>q;
    vll a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int B=sqrt(n+1);
    vector<vector<ll>>pref1(B+1,vector<ll>(n+1,0));
    vector<vector<ll>>pref2(B+1,vector<ll>(n+1,0));

    
    // int limit=min(B,n);
    for(int d=1;d<=B;d++){

        for(int i=1;i<=n;i++){
            ll p1=(i>d)?pref1[d][i-d]:0;
            ll p2=(i>d)?pref2[d][i-d]:0;
            pref1[d][i]=p1+a[i];
            pref2[d][i]=p2+a[i]*(i/d+1);
        }
    }
    while(q--){
        ll s,d,k; cin>>s>>d>>k;
        if(d>B){
            ll ans=0;
            for(int j=0;j<k;j++){
                ans+=a[s+j*d]*(1+j);
            }
            cout<<ans<<" ";
        }
        else{
            ll e=s+(k-1)*d;
            ll sum1=pref1[d][e]-((s>d)?pref1[d][s-d]:0);
            ll sum2=pref2[d][e]-((s>d)?pref2[d][s-d]:0);
            ll ans=sum2-(s/d)*sum1;
            cout<<ans<<" ";
        }
        
    }
    cout<<endl;
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}