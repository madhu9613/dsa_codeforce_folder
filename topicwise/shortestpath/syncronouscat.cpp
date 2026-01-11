#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define max3(a, b, c) max(max(a, b), c)
#define max4(a, b, c, d) max(max(a, b), max(c, d))
#define pii pair<int, int>
#define pll pair<ll, ll>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl '\n'

ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}

ll lcm(ll a, ll b)
{
    return a / gcd(a, b) * b;
}

ll pow(ll a, ll b, ll m)
{
    if (b == 0)
        return 1;
    if (b == 1)
        return a % m;
    ll temp = pow(a, b / 2, m);
    if (b % 2 == 0)
        return (temp * temp) % m;
    else
        return (a * (temp * temp % m)) % m;
}

const int MOD = 1e9 + 7;
const int INF = INT_MAX;
const ll LINF = 1e18;

struct state
{
    int cost, u, fish;
    bool operator>(const state &other) const
    {
        return cost > other.cost;
    }
};

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;

    // fishmask[i] = bitmask of fish sold at node i
    vector<int> fishmask(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        int t;
        cin >> t;
        int mask = 0;
        for (int j = 0; j < t; j++)
        {
            int x;
            cin >> x;
            mask |= (1 << (x - 1));
        }
        fishmask[i] = mask;
    }

    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].pb({b, w});
        adj[b].pb({a, w});
    }

    int fullmask = (1 << k);

    vector<vector<int>> dist(n + 1, vector<int>(fullmask, INF));

    priority_queue<state, vector<state>, greater<>> pq;

    dist[1][fishmask[1]] = 0;
    pq.push({0, 1, fishmask[1]});

    while (!pq.empty())
    {
        auto cur = pq.top();
        pq.pop();

        int cost = cur.cost;
        int u = cur.u;
        int fish = cur.fish;

        if (cost > dist[u][fish])
            continue;

        for (auto &[v, w] : adj[u])
        {
            int newmask = fish | fishmask[v];
            int newcost = cost + w;
            if (dist[v][newmask] > newcost)
            {
                dist[v][newmask] = newcost;
                pq.push({newcost, v, newmask});
            }
        }
    }

    int full = (1 << k) - 1;
    int ans = INF;

    for (int i = 0; i < (1 << k); i++)
    {
        for (int j = 0; j < (1 << k); j++)
        {
            if ((i | j) == full)
            {
                int t1 = dist[n][i];
                int t2 = dist[n][j];
                if (t1 < INF && t2 < INF)
                {
                    ans = min(ans, max(t1, t2));
                }
            }
        }
    }

    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    while (t--)
        solve();

    return 0;
}
