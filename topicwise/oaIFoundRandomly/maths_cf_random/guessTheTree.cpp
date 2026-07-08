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

// its 2nd solution
// prob link is https://codeforces.com/contest/429/problem/C

int n;
vi a; // internal nodes;
int total_leves=0;
int memo[13][1<<13][30];

bool f(int node, int mask, int leaves)
{
    int m = a.size();
    if (node == m)
    {
        return (mask == 0 && leaves == 0);
    }

    if (memo[node][mask][leaves] != -1)
    {
        return memo[node][mask][leaves];
    }

    if ((mask & (1 << node)) != 0)
    {
        return memo[node][mask][leaves] = false;
    }

    int T = a[node] - 1;
    bool posible = false;

   
    for (int sub = mask;; sub = (sub - 1) & mask)
    {
        int sum_inter = 0;
        int child = 0;
        for (int i = 0; i < m; i++)
        {
            if (sub & (1 << i))
            {
                sum_inter += a[i];
                child++;
            }
        }
        int needed = T - sum_inter;
        if (needed >= 0 && needed <= leaves)
        {
            if (child + needed >= 2)
            {
                if (f(node + 1, mask ^ sub, leaves - needed))
                {
                    posible = true;
                    break;
                }
            }
        }

        if (sub == 0)
        {
            break;
        }
    }

    return memo[node][mask][leaves] = posible;
}

void solve() {
    cin>>n;
    vi c(n);
   int max_c=0;
   int cnt_r=0;
    for(int i=0;i<n;i++){

        cin>>c[i];
        max_c=max(max_c,c[i]);
        if(c[i]==1){
            total_leves++;
        }
        else{
            a.push_back(c[i]);
        }
    }
    for(int x:c){
        if(x==n){
            cnt_r++;
        }
    }
    if(max_c!=n || cnt_r!=1){
        cout<<"NO"<<endl;
        return;
    }

    if (n == 1)
    {
        cout << (c[0] == 1 ? "YES\n" : "NO\n");
        return ;
    }

    if(total_leves<(n+1)/2){
        cout<<"NO"<<endl;
        return ;
    }

    //2I<=n

    sort(rall(a));
    memset(memo,-1,sizeof(memo));
    int m=a.size();
    int initial=(1<<m)-2;//ecept root;

    if (f(0, initial, total_leves))
    {
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
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