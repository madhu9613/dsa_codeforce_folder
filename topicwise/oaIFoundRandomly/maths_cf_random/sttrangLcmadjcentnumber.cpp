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
const int MAXN = 1e6 + 5;

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

int spf[MAXN];
int freq[MAXN];
void precomp_spf(){

    for(int i=2;i<MAXN;i++){
        spf[i]=i;
    }
    for(int i=2;i*i<MAXN;i++){
        if(spf[i]==i){
            for(int j=i*i;j<MAXN;j+=i){
                if(spf[j]==j){
                    spf[j]=i;
                }
            }
        }
    }

}
int remain(int x){
    int c=1;
    while(x>1){
        int p=spf[x];
        int cnt=0;
        while(x%p==0){
            cnt++;
            x/=p;
        }
        if(cnt%2!=0){
            c*=p;
        }
    }
    return c;
}

void solve() {

    int n;cin>>n;
    vi a;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        int c=remain(x);
        if(freq[c]==0){
            a.push_back(c);
        }
        freq[c]++;
    }

    int ans0=0;
    int sum1=freq[1];
    int maxodd=0;
    for(int c:a){
        ans0=max(ans0,freq[c]);
        if(c==1) continue;
        if(freq[c]%2==0){
            sum1+=freq[c];
        }else{
            maxodd=max(maxodd,freq[c]);
        }
    }

    int ans1=max(ans0,max(sum1,maxodd));
    int q;cin>>q;
    while(q--){
        ll w;cin>>w;
        if(w==0){
            cout<<ans0<<endl;
        }else{
            cout<<ans1<<endl;
        }
    }
    for (int c : a)
    {
        freq[c] = 0;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
   // precompute();

   precomp_spf();
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}