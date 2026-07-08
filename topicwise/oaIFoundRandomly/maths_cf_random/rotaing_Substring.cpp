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

// void solve() {
//     int n;cin>>n;
//     string s,t;cin>>s>>t;
//     vi cnts(26,0),cntt(26,0);
//     for(char c:s){
//         cnts[c-'a']++;
//     }
//     for(char c:t){
//         cntt[c-'a']++;
//     }
//     for(int i=0;i<26;i++){
//         if(cnts[i]!=cntt[i]){
//             cout<<-1<<endl;
//             return ;
//         }
//     }

//     s=" "+s;
//     t=" "+t;
//     vector<vi>suf_s(n+2,vi(26,0));
//     vector<vi>suf_t(n+2,vi(26,0));
//     // suf[i][c]=cnt of char 'c' in suffix[i..n]

//     for(int i=n;i>=1;i--){
//         for(int c=0;c<26;c++){
//             suf_s[i][c]=suf_s[i+1][c];
//             suf_t[i][c]=suf_t[i+1][c];
//         }
//         suf_s[i][s[i]-'a']++;
//         suf_t[i][t[i]-'a']++;

//     }

//     vector<vi>dp(n+1,vi(n+1,INT_MAX));
//     dp[0][0]=0;  // okay to match [0] char from s and [0] from t req 0 cost;

//     for(int i=0;i<=n;i++){
//         for(int j=0;j<=n;j++){

//             // pick up s[i] and put it in bank i dec and j remain same cost+1 as we pick this ;
//             if(i>0){
//                 dp[i][j]=min(dp[i][j],dp[i-1][j]+1);
//             }

//             //okay s[i] and s[j] both match 
//             if(i>0 && j>0 && s[i]==t[j]){
//                 dp[i][j]=min(dp[i][j],dp[i-1][j-1]);
//             }

//             if(j>0){
//                 int cneed=t[j]-'a';
//                 // can i use bank ;
//                 if(suf_s[i+1][cneed]>suf_t[j+1][cneed]){
//                     dp[i][j]=min(dp[i][j],dp[i][j-1]);
//                 }
//             }
//         }
//     }

//     // min time for build the full 
//     cout<<dp[n][n]<<endl;


// }

void solve(){
    int n;cin>>n;
    string s,t;cin>>s>>t;
    s=" "+s;
    t=" "+t;
    vector<vi>pref_s(n+1,vi(26,0));
    vector<vi>pref_t(n+1,vi(26,0));
    for(int i=1;i<=n;i++){
        for(int c=0;c<26;c++){
            pref_s[i][c]=pref_s[i-1][c];
            pref_t[i][c]=pref_t[i-1][c];
        }
        pref_s[i][s[i]-'a']++;
        pref_t[i][t[i]-'a']++;
    }

    for(int c=0;c<26;c++){
        if(pref_s[n][c]!=pref_t[n][c]){
            cout<<-1<<endl;
            return;
        }
    }

    vector<vi>dp(n+1,vi(n+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);

            if(s[i]==t[j]){
                bool valid=true;
                for(char c=0;c<26;c++){
                    if(pref_s[i-1][c]>pref_t[j-1][c]){
                        valid=false;
                        break;
                    }
                }
                if (valid)
                {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
                }
            }
        }

    }

    cout<<n-dp[n][n]<<endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
   // precompute();
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}