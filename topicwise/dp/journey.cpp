// Author: Madhujya Rajkhowa
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define all(x) (x).begin(), (x).end()
#define endl '\n'

const ll INF = 1e18;
ll n, m;
ll T;
vector<vector<pair<ll, ll>>> adj;
vector<ll> topo_order;

void topo_sort()
{
    vector<int> indegree(n + 1, 0);
    for (int u = 1; u <= n; ++u)
        for (auto &[v, _] : adj[u])
            indegree[v]++;
    queue<int> q;
    for (int i = 1; i <= n; ++i)
        if (indegree[i] == 0)
            q.push(i);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        topo_order.push_back(u);
        for (auto &[v, _] : adj[u])
            if (--indegree[v] == 0)
                q.push(v);
    }
}

void solve()
{
    cin >> n >> m >> T;
    adj.resize(n + 1);
    for (ll i = 1; i <= m; ++i)
    {
        ll a, b;
        ll c;
        cin >> a >> b >> c;
        adj[a].pb({b, c});
    }

    topo_sort();
    vector<ll> dp(n + 1);
    vector<ll> len(n + 1);
    vector<ll> parent(n + 1);
    for (ll i = 1; i <= n; i++)
    {
        dp[i] = INF;
        len[i] = 0;
        parent[i] = -1;
    }

    dp[1] = 0;
    len[1] = 1; // max nodes to reach 1 from 1 is 1;
    for (auto u : topo_order)
    {
        for (auto &[v, cost] : adj[u])
        {
            if (dp[u] + cost <= T)
            {
                if (len[u] + 1 > len[v] || (len[u] + 1 == len[v] && dp[u] + cost < dp[v]))
                {
                    len[v] = len[u] + 1;
                    dp[v] = dp[u] + cost;
                    parent[v] = u;
                }
            }
        }
    }

    vector<ll> path;
    ll curr = n;
    while (curr != -1)
    {
        path.push_back(curr);
        curr = parent[curr];
    }
    reverse(path.begin(), path.end());
    cout << len[n] << endl;
    for (ll x : path)
        cout << x << " ";
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}

