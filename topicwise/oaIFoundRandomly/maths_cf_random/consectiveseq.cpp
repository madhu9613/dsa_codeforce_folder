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
    vll a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    unordered_map<ll,ll>dp;
    ll bestlen=0;
    ll bestend=-1;
    for(auto &x:a){

        dp[x]=1;
        if(dp.count(x-1)){
            dp[x]+=dp[x-1];
        }
        if(dp[x]>bestlen){
            bestlen=dp[x];
            bestend=x;
        }
    }

    vi idx;
    ll need=bestend;
    for(int i=n-1;i>=0;i--){
        if(need==a[i]){
            idx.push_back(i+1);
            need--;
        }
    }
    reverse(all(idx));
    cout<<bestlen<<endl;
    for(int i:idx){
        cout<<i<<" ";
    }cout<<endl;
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}