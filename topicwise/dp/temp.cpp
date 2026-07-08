#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 300005;

vector<int> g[N];
int depth[N], sz[N];

void dfs(int u, int p)
{
    sz[u] = 1;
    for (int v : g[u])
    {
        if (v == p)
            continue;
        depth[v] = depth[u] + 1;
        dfs(v, u);
        sz[u] += sz[v];
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        for (int i = 1; i <= n; i++)
        {
            g[i].clear();
        }

        for (int i = 1; i < n; i++)
        {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        depth[1] = 0;
        dfs(1, 0);

        vector<int> score;

        for (int i = 1; i <= n; i++)
        {
            score.push_back(depth[i] - (sz[i] - 1));
        }

        sort(score.rbegin(), score.rend());

        ll ans = 0;
        for (int i = 0; i < k; i++)
        {
            ans += score[i];
        }

        cout << ans << '\n';
    }
}