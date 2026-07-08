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

vector<int> primes;
bool isPrime[MAXN];
void sieve(int n) {
    fill(isPrime, isPrime + n + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) isPrime[j] = false;
        }
    }
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) primes.push_back(i);
    }
}

int phi[MAXN];
void sievePhi(int n) {
    for (int i = 0; i <= n; i++) phi[i] = i;
    for (int i = 2; i <= n; i++) {
        if (phi[i] == i) {
            for (int j = i; j <= n; j += i) {
                phi[j] -= phi[j] / i;
            }
        }
    }
}

using Matrix = vector<vector<ll>>;
Matrix matMul(Matrix A, Matrix B) {
    int rA = A.size(), cA = A[0].size(), cB = B[0].size();
    Matrix C(rA, vector<ll>(cB, 0));
    for (int i = 0; i < rA; i++) {
        for (int k = 0; k < cA; k++) {
            for (int j = 0; j < cB; j++) {
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
            }
        }
    }
    return C;
}

Matrix matPow(Matrix A, ll p) {
    int n = A.size();
    Matrix res(n, vector<ll>(n, 0));
    for (int i = 0; i < n; i++) res[i][i] = 1;
    while (p > 0) {
        if (p & 1) res = matMul(res, A);
        A = matMul(A, A);
        p >>= 1;
    }
    return res;
}

ll dp[205][205][205];

void solve() {
    int n,k;cin>>n>>k;
    string s,t;cin>>s>>t;
    if(t[0]==t[1]){
        ll cnt0=0;
        for(char c:s){
            if(c==t[0]) cnt0++;
        }
        ll total=min((ll)n,cnt0+k);
        cout<<total*(total-1)/2<<endl;
        return ;
    }
 

    memset(dp,-1,sizeof(dp));
    dp[0][0][0]=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<=k;j++){
            for(int c0=0;c0<=i;c0++){
                if(dp[i][j][c0]==-1) continue;
                int nxtc0=c0+(s[i]==t[0])?1:0;
                ll score=(s[i]==t[1])?c0:0;
                dp[i+1][j][nxtc0]=max(dp[i+1][j][nxtc0],dp[i][j][c0]+score);
                //change s[i]->t[0];
                if(j+1<=k){
                    dp[i+1][j+1][c0+1]=max(dp[i+1][j+1][c0+1],dp[i][j][c0]);
                }

                if(j+1<=k){
                    dp[i+1][j+1][c0]=max(dp[i+1][j+1][c0],dp[i][j][c0]+c0);
                }

            }
        }
    }

    ll ans=0;
    for(int j=0;j<=k;j++){
        for(int c0=0;c0<=n;c0++){
            ans=max(ans,dp[n][j][c0]);
        }
    }
    cout<<ans<<endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
   // precompute();
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}