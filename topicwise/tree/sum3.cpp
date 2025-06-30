#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<vector<int>> adj;
vector<int> s;
vector<int> a;
int ans;

void dfs(int cur, int par)
{
    int s_parent = 0;
    if (par != -1)
    {
        s_parent = s[par];
    }

    // First process children
   

    // Now process the current node
    if (s[cur] == -1)
    {
        int minv = INT_MAX;
        for (auto &ch : adj[cur])
        {
            minv = min(minv, s[ch]);
        }
        if (adj[cur].size() == 0)
        {
            minv = s_parent;
        }
        s[cur] = minv;
    }

    a[cur] = s[cur] - s_parent;
    ans += a[cur];

    for (auto &child : adj[cur])
    {
        dfs(child, cur);
    }
}

int32_t main()
{
    int n;
    cin >> n;

    adj.resize(n + 1);
    s.resize(n + 1);
    a.resize(n + 1);

    for (int i = 2; i <= n; ++i)
    {
        int boss;
        cin >> boss;
        adj[boss].push_back(i);
    }

    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
    }

    ans = 0;
    dfs(1, -1);

   
    bool pos = true;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] < 0)
        {
            pos = false;
            break;
        }
    }

    if (pos)
    {
        cout << ans << endl;
    }
    else
    {
        cout << -1 << endl;
    }

    return 0;
}
