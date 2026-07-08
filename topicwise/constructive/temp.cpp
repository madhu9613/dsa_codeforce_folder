#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> r(n), indeg(n, 0);

        for (int i = 0; i < n; i++)
        {
            cin >> r[i];
            r[i]--;
            indeg[r[i]]++;
        }

        // Step 1: remove non-cycle nodes
        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            if (indeg[i] == 0)
                q.push(i);
        }

        int layers = 0;

        while (!q.empty())
        {
            int sz = q.size();
            layers++;

            while (sz--)
            {
                int u = q.front();
                q.pop();
                int v = r[u];

                indeg[v]--;
                if (indeg[v] == 0)
                    q.push(v);
            }
        }

        int D = layers;

        // Step 2: find cycle lengths
        vector<bool> vis(n, false);
        int maxCycle = 0;

        for (int i = 0; i < n; i++)
        {
            if (!vis[i] && indeg[i] > 0)
            {
                int cur = i, cnt = 0;

                while (!vis[cur])
                {
                    vis[cur] = true;
                    cur = r[cur];
                    cnt++;
                }

                maxCycle = max(maxCycle, cnt);
            }
        }

        cout << max(D + 2, maxCycle) << '\n';
    }

    return 0;
}