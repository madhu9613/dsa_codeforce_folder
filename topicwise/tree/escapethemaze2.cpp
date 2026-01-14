#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

vector<int> dist;
vector<vector<int>> adj;

int dfs(int u, int depth, int p)
{
    int need = 0;
    bool block = true;

    for (int v : adj[u])
    {
        if (v == p)
            continue;

        int child = dfs(v, depth + 1, u);
        if (child == -1)
            block = false;

        need += child;
        dist[u] = min(dist[u], dist[v] + 1);
    }

    // friend catches Vlad here
    if (dist[u] <= depth)
        return 1;

    // leaf (except root) or unblockable child
    if (!block || (need == 0 && u != 1))
        return -1;

    return need;
}

void solve()
{
    int n, k;
    cin >> n >> k;

    dist.assign(n + 1, INF);
    adj.assign(n + 1, vector<int>());

    for (int i = 0; i < k; i++)
    {
        int x;
        cin >> x;
        dist[x] = 0;
    }

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int res = dfs(1, 0, -1);

    cout<<res<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
