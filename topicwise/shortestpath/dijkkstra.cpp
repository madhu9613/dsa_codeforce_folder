// https://codeforces.com/problemset/problem/20/C

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const ll LINF = (ll)4e18;

struct node
{
    int v;
    ll cost;
};

struct cmp
{
    bool operator()(const node &a, const node &b)
    {
        return a.cost > b.cost; // min-heap
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n + 1);

    for (int i = 0; i < m; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }

    vector<ll> dist(n + 1, LINF);
    vector<int> par(n + 1, -1);

    priority_queue<node, vector<node>, cmp> pq;

    dist[1] = 0;
    pq.push({1, 0});

    while (!pq.empty())
    {
        auto cur = pq.top();
        pq.pop();
        int u = cur.v;
        ll cost = cur.cost;

        if (cost > dist[u])
            continue;

        for (auto &[v, w] : adj[u])
        {
            if (dist[v] > cost + w)
            {
                dist[v] = cost + w;
                par[v] = u;
                pq.push({v, dist[v]});
            }
        }
    }

    if (dist[n] == LINF)
    {
        cout << -1 << endl;
        return 0;
    }

    vector<int> path;
    for (int v = n; v != -1; v = par[v])
        path.push_back(v);

    reverse(path.begin(), path.end());

    for (int x : path)
        cout << x << " ";
    cout << endl;

    return 0;
}
