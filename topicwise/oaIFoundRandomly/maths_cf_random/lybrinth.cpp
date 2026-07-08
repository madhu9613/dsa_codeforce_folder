#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define vi vector<int>
#define vll vector<ll>
#define vpi vector<pii>
#define vpll vector<pll>

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

const ll INF = 1e18;
const int MOD = 1000000007;
const int MAXN = 2e5 + 5;

ll modpow(ll a, ll b, ll mod = MOD)
{
    ll res = 1;
    a %= mod;
    while (b)
    {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

ll modinv(ll a, ll mod = MOD)
{
    return modpow(a, mod - 2, mod);
}

ll gcd(ll a, ll b)
{
    return b ? gcd(b, a % b) : a;
}

ll lcm(ll a, ll b)
{
    return a / gcd(a, b) * b;
}

ll fact[MAXN], invFact[MAXN];
void precompute()
{
    fact[0] = 1;
    invFact[0] = 1;
    for (int i = 1; i < MAXN; i++)
    {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    invFact[MAXN - 1] = modinv(fact[MAXN - 1]);
    for (int i = MAXN - 2; i >= 1; i--)
    {
        invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
    }
}

ll nCr(int n, int r)
{
    if (r < 0 || r > n)
        return 0;
    return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
}

vector<int> primes;
bool isPrime[MAXN];
void sieve(int n)
{
    fill(isPrime, isPrime + n + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= n; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= n; j += i)
                isPrime[j] = false;
        }
    }
    for (int i = 2; i <= n; i++)
    {
        if (isPrime[i])
            primes.push_back(i);
    }
}

int phi[MAXN];
void sievePhi(int n)
{
    for (int i = 0; i <= n; i++)
        phi[i] = i;
    for (int i = 2; i <= n; i++)
    {
        if (phi[i] == i)
        {
            for (int j = i; j <= n; j += i)
            {
                phi[j] -= phi[j] / i;
            }
        }
    }
}

using Matrix = vector<vector<ll>>;
Matrix matMul(Matrix A, Matrix B)
{
    int rA = A.size(), cA = A[0].size(), cB = B[0].size();
    Matrix C(rA, vector<ll>(cB, 0));
    for (int i = 0; i < rA; i++)
    {
        for (int k = 0; k < cA; k++)
        {
            for (int j = 0; j < cB; j++)
            {
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
            }
        }
    }
    return C;
}

Matrix matPow(Matrix A, ll p)
{
    int n = A.size();
    Matrix res(n, vector<ll>(n, 0));
    for (int i = 0; i < n; i++)
        res[i][i] = 1;
    while (p > 0)
    {
        if (p & 1)
            res = matMul(res, A);
        A = matMul(A, A);
        p >>= 1;
    }
    return res;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n; i++)
    {
        cin >> grid[i];
    }

    vector<vector<int>> comp_id(n, vi(m, 0));
    vi comp_size(n * m + 1, 0);
    int id = 1;

    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '.' && comp_id[i][j] == 0)
            {

                queue<pair<int, int>> q;
                q.push({i, j});
                comp_id[i][j] = id;
                int sz = 0;
                while (!q.empty())
                {
                    auto [x, y] = q.front();
                    q.pop();
                    sz++;
                    for (int d = 0; d < 4; d++)
                    {

                        int nx = x + dx[d];
                        int ny = y + dy[d];
                        if (nx >= 0 && nx < n && ny >= 0 && ny < m)
                        {
                            if (grid[nx][ny] == '.' && comp_id[nx][ny] == 0)
                            {
                                comp_id[nx][ny] = id;
                                q.push({nx, ny});
                            }
                        }
                    }
                }
                comp_size[id] = sz;
                id++;
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='.'){
                cout<<'.';
            }else{
                set<int>adj;


                for(int d=0;d<4;d++){
                    int ni=i+dx[d];
                    int nj=j+dy[d];
                    if(ni>=0 && ni<n && nj>=0 && nj<m && grid[ni][nj]=='.')
                    {
                       adj.insert(comp_id[ni][nj]);
                    }
                }
                int ans=1;
                for(int id:adj){
                    ans+=comp_size[id];
                }
                cout<<ans%10;
            }
        }
        cout<<endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // precompute();
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t = 1;
    while (t--)
        solve();
    return 0;
}