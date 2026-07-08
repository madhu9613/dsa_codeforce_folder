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
const int MAXN = 5000 + 5;

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

    // Use standard int for T since max is 10^9
    int T;
    cin >> T;

    // Standard int for time limits
    vector<vector<pair<int, int>>> adj(n + 1);

    // MEMORY FIX: Use short instead of int. Max N is 5000, short goes up to 32767.
    vector<vector<short>> par(n + 1, vector<short>(n + 1, 0));
    vi indeg(n + 1, 0);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        int t; // int is enough for t
        cin >> u >> v >> t;

        adj[u].push_back({v, t});
        indeg[v]++;
    }

    /*
        dp[u][cnt] =
        minimum time needed to reach node u
        using exactly cnt nodes
    */

    // MEMORY FIX: Use standard int. 2e9 represents infinity but fits inside 32 bits.
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 2e9));
    dp[1][1] = 0;

    queue<int> q;

    for (int i = 1; i <= n; i++)
    {
        if (indeg[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (auto &[v, t] : adj[u])
        {
            for (int j = 1; j < n; j++)
            {
                if (dp[u][j] == 2e9)
                    continue;

                if (dp[u][j] + t <= T && dp[u][j] + t < dp[v][j + 1])
                {
                    dp[v][j + 1] = dp[u][j] + t;
                    par[v][j + 1] = u;
                }
            }

            if (--indeg[v] == 0)
            {
                q.push(v);
            }
        }
    }

    int maxnode = 0;

    for (int j = n; j >= 1; j--)
    {
        if (dp[n][j] <= T)
        {
            maxnode = j;
            break;
        }
    }

    cout << maxnode << "\n";

    vi path;

    int cur = n;
    int cnt = maxnode;

    while (cnt > 0)
    {
        path.push_back(cur);
        cur = par[cur][cnt];
        cnt--;
    }

    reverse(all(path));

    for (int x : path)
    {
        cout << x << " ";
    }

    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}