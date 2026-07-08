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
    int k,n,maxb;cin>>k>>n>>maxb;
    ll t; cin>>t;
    while(k--){
        vi b(n);
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
        vi vals=b;
        sort(all(vals));
        vals.erase(unique(all(vals)),vals.end());
        int m=vals.size();
        unordered_map<int,int>mp;
        for(int i=0;i<m;i++){
            mp[vals[i]]=i;
        }
        vi a(n);
        for(int i=0;i<n;i++){
            a[i]=mp[b[i]];
        }
        vector<vector<int>>next(n+1,vector<int>(m,-1));
        for(int j=0;j<m;j++){
            next[n][j]=-1;
        }
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<m;j++){
                next[i][j]=next[i+1][j];
            }
            next[i][a[i]]=i;
        }

        vi first(m,-1);
        for(int i=0;i<n;i++){
            if(first[a[i]]==-1){
                first[a[i]]=i;
            }
        }

        vector<vector<int>>dp(n+1,vi(m,INF));
        for(int j=0;j<m;j++){
            dp[1][j]=1;
        }
        int ans=1;
        for(int len=1;len<n;len++){
            for(int last=0;last<m;last++){
                if(dp[len][last]>t){
                    continue;
                }
                for(int nx)
            }
        }
        

    
    
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
   
    while (t--) solve();

    return 0;
}