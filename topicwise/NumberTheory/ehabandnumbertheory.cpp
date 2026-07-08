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

// Fast exponentiation (a^b % mod)
ll modpow(ll a, ll b, ll mod = MOD)
{
    ll res = 1;
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

// GCD
ll gcd(ll a, ll b)
{
    return b ? gcd(b, a % b) : a;
}

// LCM
ll lcm(ll a, ll b)
{
    return a / gcd(a, b) * b;
}

const int MAXA = 1e6 + 5;
int spf[MAXA];

vector<int> g[MAXA];
int dist[MAXA], par[MAXA], vis[MAXA];
int timer = 1;

void sieve()
{
    for (int i = 1; i < MAXA; i++)
        spf[i] = i;
    for (int i = 2; i * i < MAXA; i++)
    {
        if (spf[i] == i)
        {
            for (int j = i * i; j < MAXA; j += i)
            {
                if (spf[j] == j)
                    spf[j] = i;
            }
        }
    }
}

// Renamed from reduce to get_reduced to avoid conflicts with std::reduce
vi get_reduced(int x)
{
    vi res;
    while (x > 1)
    {
        int p = spf[x], cnt = 0;
        while (x % p == 0)
        {
            x /= p;
            cnt++;
        }
        if (cnt % 2)
            res.push_back(p);
    }
    return res;
}

void solve()
{
    for (int i = 1; i < MAXA; i++)
    {
        g[i].clear();
    }

    int n;
    cin >> n;

    vi a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // Precompute reduced vectors to avoid repeating factorization
    vector<vi> reduced_a(n);

    // Pass 1: Strictly check for perfect squares (Answer = 1)
    for (int i = 0; i < n; i++)
    {
        reduced_a[i] = get_reduced(a[i]);
        if (reduced_a[i].empty())
        {
            cout << 1 << '\n';
            return;
        }
    }

    map<pair<int, int>, int> cnt;

    // Pass 2: Check for cycles of length 2 and build graph
    for (int i = 0; i < n; i++)
    {
        auto &p = reduced_a[i];

        if (p.size() == 1)
            p.push_back(1);

        int u = p[0], v = p[1];
        if (u > v)
            swap(u, v);

        if (++cnt[{u, v}] >= 2)
        {
            cout << 2 << '\n';
            return;
        }

        g[u].push_back(v);
        g[v].push_back(u);
    }

    int ans = INT_MAX;

    for (int start = 1; start <= 1000; start++)
    {
        if (g[start].empty())
            continue;

        queue<int> q;
        timer++;

        dist[start] = 0;
        vis[start] = timer;
        par[start] = -1;
        q.push(start);

        while (!q.empty())
        {
            int u = q.front();
            q.pop();

            if (dist[u] * 2 + 1 >= ans)
                continue;

            for (int v : g[u])
            {
                if (vis[v] != timer)
                {
                    vis[v] = timer;
                    dist[v] = dist[u] + 1;
                    par[v] = u;
                    q.push(v);
                }
                else if (par[u] != v)
                {
                    ans = min(ans, dist[u] + dist[v] + 1);
                }
            }
        }
    }

    if (ans == INT_MAX)
        cout << -1 << '\n';
    else
        cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    sieve();
    // cin >> t;
    while (t--)
        solve();

    return 0;
}