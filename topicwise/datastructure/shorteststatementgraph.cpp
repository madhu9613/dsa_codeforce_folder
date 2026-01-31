#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

const ll LINF = 4e18;
const int LOG = 18;

struct Dsu
{
    vi p;
    Dsu(int n) : p(n + 1) { iota(all(p), 0); }
    int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }
    bool unite(int a, int b)
    {
        a = find(a);
        b = find(b);
        if (a == b)
            return false;
        p[a] = b;
        return true;
    }
};

int n, m;
vector<vector<pair<int, ll>>> tree;
vi depth;
vll dist;
vector<vector<int>> par;

void dfs(int u, int p)
{
    for (auto &[v, w] : tree[u])
    {
        if (v == p)
            continue;
        depth[v] = depth[u] + 1;
        dist[v] = dist[u] + w;
        par[0][v] = u;
        dfs(v, u);
    }
}

int lca(int u, int v)
{
    if (depth[u] < depth[v])
        swap(u, v);
    for (int i = 0; i < LOG; i++)
        if ((depth[u] - depth[v]) & (1 << i))
            u = par[i][u];
    if (u == v)
        return u;
    for (int i = LOG - 1; i >= 0; i--)
        if (par[i][u] != par[i][v])
        {
            u = par[i][u];
            v = par[i][v];
        }
    return par[0][u];
}

ll dist_tree(int u, int v)
{
    int w = lca(u, v);
    return dist[u] + dist[v] - 2 * dist[w];
}

void solve()
{
    cin >> n >> m;
    vector<tuple<int, int, ll>> edges(m);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        edges[i] = {u, v, w};
    }

    tree.assign(n + 1, {});
    Dsu dsu(n);
    vector<tuple<int, int, ll>> extra;

    for (auto [u, v, w] : edges)
    {
        if (dsu.unite(u, v))
        {
            tree[u].push_back({v, w});
            tree[v].push_back({u, w});
        }
        else
        {
            extra.push_back({u, v, w});
        }
    }

    depth.assign(n + 1, 0);
    dist.assign(n + 1, 0);
    par.assign(LOG, vi(n + 1, 0));

    dfs(1, 0);
    for (int i = 1; i < LOG; i++)
        for (int v = 1; v <= n; v++)
            par[i][v] = par[i - 1][par[i - 1][v]];

    vi special;
    for (auto [u, v, w] : extra)
    {
        special.push_back(u);
        special.push_back(v);
    }

    sort(all(special));
    special.erase(unique(all(special)), special.end());

    int k = special.size();
    auto idx = [&](int x)
    {
        return lower_bound(all(special), x) - special.begin();
    };

    vector<vector<ll>> dist2(k, vector<ll>(k, LINF));
    for (int i = 0; i < k; i++)
        for (int j = 0; j < k; j++)
            dist2[i][j] = dist_tree(special[i], special[j]);

    for (auto [u, v, w] : extra)
    {
        int i = idx(u), j = idx(v);
        dist2[i][j] = min(dist2[i][j], w);
        dist2[j][i] = min(dist2[j][i], w);
    }

    for (int kk = 0; kk < k; kk++)
        for (int i = 0; i < k; i++)
            for (int j = 0; j < k; j++)
                dist2[i][j] = min(dist2[i][j], dist2[i][kk] + dist2[kk][j]);

    int q;
    cin >> q;
    while (q--)
    {
        int u, v;
        cin >> u >> v;

        ll ans = dist_tree(u, v);

        vector<ll> du(k), dv(k);
        for (int i = 0; i < k; i++)
            du[i] = dist_tree(u, special[i]);
        for (int j = 0; j < k; j++)
            dv[j] = dist_tree(special[j], v);

        for (int i = 0; i < k; i++)
            for (int j = 0; j < k; j++)
                ans = min(ans, du[i] + dist2[i][j] + dv[j]);

        cout << ans << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
