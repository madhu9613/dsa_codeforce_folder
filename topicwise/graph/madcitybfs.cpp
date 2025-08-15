#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define max3(a, b, c) max(max(a, b), c)
#define max4(a, b, c, d) max(max(a, b), max(c, d))
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()
#define endl '\n'

ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}
const int MOD = 1e9 + 7;
const int INF = INT_MAX;
const int MAXN = 2e5 + 5;
vi adj[MAXN];
vector<bool> visited(MAXN);
int entry_point = -1;

bool dfs1(int u, int p = -1)
{
    visited[u] = true;
    for (int v : adj[u])
    {
        if (v == p)
            continue;
        if (visited[v])
        {
            entry_point = v;
            return true;
        }
        else
        {
            if (dfs1(v, u))
            {
                return true;
            }
        }
    }
    return false;
}

int bfs(int u)
{
    vector<int> dist(MAXN, INF);
    queue<int> q;
    q.push(u);
    dist[u] = 0;
    while (!q.empty())
    {
        int cnode = q.front();
        q.pop();
        for (int v : adj[cnode])
        {
            if (dist[v] == INF)
            {
                dist[v] = dist[cnode] + 1;
                q.push(v);
            }
        }
    }

    return dist[entry_point];
}

void solve()
{
    int n, a, b;
    cin >> n >> a >> b;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    dfs1(b);
    int distM = bfs(a);
    int distV = bfs(b);
    if (distV < distM)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    for (int i = 0; i <= n; i++)
    {
        adj[i].clear();
        visited[i] = false;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}