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


struct Item{
    int t;
    int d;
    int p;
    int id;
};

bool comp(const Item &a, const Item &b)
{
    return a.d < b.d;
}
void solve() {
    int n;
    cin>>n;
    vector<Item>items(n);
    for(int i=0;i<n;i++){
        int t,d,p;
        cin>>t>>d>>p;
        items[i]={t,d,p,i+1};
    }
    sort(all(items),comp);
    int max_d=2000;
    vector<vi>dp(n+1,vi(max_d+1,0));
    for(int i=1;i<=n;i++){
        int c_t=items[i-1].t;
        int c_d=items[i-1].d;
        int c_p=items[i-1].p;
        for(int j=0;j<=max_d;j++){
            dp[i][j]=dp[i-1][j];
            if(j>=c_t && j<c_d){
                dp[i][j]=max(dp[i][j],dp[i-1][j-c_t]+c_p);
            }
        }
    }
    int max_val=0;
    int best=0;
    for(int j=0;j<=max_d;j++){
        if(dp[n][j]>max_val){
            max_val=dp[n][j];
            best=j;
        }
    }
    vector<int> saved_items;
    int curr_time = best;

    for (int i = n; i > 0; --i)
    {
        if (dp[i][curr_time] != dp[i - 1][curr_time])
        {
            saved_items.push_back(items[i - 1].id);
            curr_time -= items[i - 1].t;
        }
    }

    reverse(saved_items.begin(), saved_items.end());

    cout << max_val << "\n";
    cout << saved_items.size() << "\n";
    for (int i = 0; i < saved_items.size(); ++i)
    {
        cout << saved_items[i] << (i == saved_items.size() - 1 ? "" : " ");
    }
    cout << "\n";
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