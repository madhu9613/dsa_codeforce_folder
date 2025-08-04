#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll, int>
const ll INF = 1e18;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    vector<vector<pii>> adj(n + 2); // 1-based, node n+1 is virtual
    for (int i = 0; i < m; i++)
    {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        adj[u].emplace_back(w, v);
        adj[v].emplace_back(w, u);
    }

    // Add teleportation edges from virtual node (n+1)
    int virtual_node = n + 1;
    for (int i = 1; i <= n; i++)
    {
        adj[i].push_back({a[i], virtual_node});
        adj[virtual_node].push_back({a[i], i});
    }

    vector<int> b(k);
    for (int i = 0; i < k; i++)
        cin >> b[i];

    for (int src : b)
    {
        vector<ll> dist(n + 2, INF);
        priority_queue<pii, vector<pii>, greater<pii>> pq;

        dist[src] = 0;
        pq.emplace(0, src);

        while (!pq.empty())
        {
            auto [d, u] = pq.top();
            pq.pop();
            if (d > dist[u])
                continue;

            for (auto &[w, v] : adj[u])
            {
                if (dist[v] > dist[u] + w)
                {
                    dist[v] = dist[u] + w;
                    pq.emplace(dist[v], v);
                }
            }
        }

        for (int i = 1; i <= n; i++)
        {
            cout << dist[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}
