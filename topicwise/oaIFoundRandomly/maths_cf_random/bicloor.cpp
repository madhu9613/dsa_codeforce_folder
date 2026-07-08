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
const int MOD = 998244353;
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

ll dp[1005][2005][4];
//s=0,1,2,3;

int get_delta(int a,int b){
    if(a==0){
        if(b==0){
            return 0;
        }else{
            return 1;
        }
    }
    else if(a==3){
        if(b==3){
            return 0;
        }else{
            return 1;
        }
    }
    else if(a==1){
        if(b==1){
            return 0;
        }
        else if(b==2){
            return 2;
        }
        else{
            return 0;
        }
    }

    else if(a==2){
        if(b==2){
            return 0;
        }else if(b==1){
            return 2;
        }else{
            return 0;
        }
    }
    return 0;
}



void solve() {
    int n,k;cin>>n>>k;
    memset(dp,0,sizeof(dp));
    dp[1][1][0]=1;
    dp[1][2][1]=1;
    dp[1][2][2]=1;
    dp[1][1][3]=1;
    for(int i=1;i<n;i++){
        for(int j=1;j<=2*i;j++){
            for(int prev=0;prev<4;prev++){
                if(dp[i][j][prev]==0){
                    continue;
                }
                for(int cur=0;cur<4;cur++){
                    int new_k=j+get_delta(prev,cur);
                    dp[i+1][new_k][cur]=(dp[i+1][new_k][cur]+dp[i][j][prev])%MOD;
                }
            }
        }
    }

    ll ways=(dp[n][k][0]+dp[n][k][1]+dp[n][k][2]+dp[n][k][3])%MOD;
    cout<<ways<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
   // precompute();
    int t = 1;
    while (t--) solve();
    return 0;
}