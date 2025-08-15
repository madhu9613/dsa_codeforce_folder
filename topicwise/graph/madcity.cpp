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
int entry_point = -1;
vector<bool> visited(MAXN);

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

int dfs2(int u)
{
    visited[u] = true;
    int distance = MAXN;
    for (int v : adj[u])
    {
        if (v == entry_point)
        {
            return 1;
        }
        if (!visited[v])
        {
            int dist = 1 + dfs2(v);
            distance = min(distance, dist);
        }
    }
    return distance;
}
void solve()
{

    int n, a, b;
    cin >> n >> a >> b;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs1(b);
    visited.assign(n + 1, false);
    int distM=MAXN, distV=0;
    if (entry_point == a)
    {
        distM = 0;
    }
    else
    {
        distM = dfs2(a);
    }

    visited.assign(n + 1, false);
    if (entry_point == b)
    {
        distV = 0;
    }
    else
    {
        distV = dfs2(b);
    }
    if (distV < distM)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    for (int i = 1; i <= n; i++)

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