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

ll fact[MAXN], invFact[MAXN];
void precompute() {
    fact[0] = 1;
    invFact[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    invFact[MAXN - 1] = modinv(fact[MAXN - 1]);
    for (int i = MAXN - 2; i >= 1; i--) {
        invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
    }
}

ll nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
}


void solve() {
    int H,W;
    cin>>H>>W;
    int N;
    cin>>N;
    vector<pair<int,int>>obst;
    for(int i=0;i<N;i++){
        int r,c;cin>>r>>c;
        obst.push_back({r,c});
    }
    obst.push_back({H,W});
    sort(all(obst));
    vll dp(N+1); // dp[i]=no of wasys to reach obst (i) without touching any prev one;

    for(int i=0;i<=N;i++){

        int r=obst[i].first;
        int c=obst[i].second;
        int dx=r-1;
        int dy=c-1;
        int d=dx+dy;

        dp[i]=nCr(d,dx);
        for(int j=0;j<i;j++){
           int rj=obst[j].first;
           int cj=obst[j].second;
           if(rj<=r && cj<=c){

            dx=r-rj;
            dy=c-cj;
            d=dx+dy;
            ll ways=nCr(d,dx);
            dp[i] = (dp[i] - (ways * dp[j]) % MOD + MOD) % MOD;
           }
        }
    }

    cout<<dp[N]<<endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
   precompute();
    int t = 1;
    while (t--) solve();
    return 0;
}