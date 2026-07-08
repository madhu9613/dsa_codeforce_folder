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

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vi> adj(n + 1);
    vi deg(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }
    int cnt = 0;
    vi vis(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            queue<int> q;
            vis[i] = 1;
            q.push(i);
            bool iscylic = true;
            while (!q.empty())
            {
                int u = q.front();
                q.pop();

                if (deg[u] != 2)
                {
                    iscylic = false; // not to be counted but we need mark all v of this comp 1 so we must continue;
                }

                for (int v : adj[u])
                {
                    if (!vis[v])
                    {
                        q.push(v);
                        vis[v] = 1;
                    }
                }
            }

            if (iscylic)
            {
                cnt++;
            }
        }
    }

    cout << cnt << endl;
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