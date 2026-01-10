// https://codeforces.com/problemset/problem/1304/E

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define max3(a, b, c) max(max(a, b), c)
#define max4(a, b, c, d) max(max(a, b), max(c, d))
#define pii pair<int, int>
#define pll pair<ll, ll>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl '\n'

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}
ll pow(ll a,ll b,ll m)
{
if(b==0)
 return 1;
if(b==1) return a%m;
 ll temp=pow(a,b/2,m);
 if(b%2==0)
 {
 return (temp*temp)%m;
}
else
{
return (a*(temp*temp)%m)%m ;
}
}

const int MOD = 1e9 + 7;
const int INF = INT_MAX;
const ll LINF = 1e18;
const int MAXN = 100005;
const int LOG = 20;

int depth[MAXN];
int up[LOG][MAXN];
vector<vector<int>> adj;

void dfs(int u, int p)
{
    up[0][u] = p;
    for (int v : adj[u])
    {
        if (v == p)
            continue;
        depth[v] = depth[u] + 1;
        dfs(v, u);
    }
}

int lca(int u, int v)
{
    if (depth[u] < depth[v])
        swap(u, v);

    int diff = depth[u] - depth[v];
    for (int i = 0; i < LOG; i++)
    {
        if (diff & (1 << i))
        {
            u = up[i][u];
        }
    }

    if (u == v)
        return u;

    for (int i = LOG - 1; i >= 0; i--)
    {
        if (up[i][u] != up[i][v])
        {
            u = up[i][u];
            v = up[i][v];
        }
    }
    return up[0][u];
}

int dist(int u, int v)
{
    int w = lca(u, v);
    return depth[u] + depth[v] - 2 * depth[w];
}

void solve()
{
    int n;
    cin >> n;

    adj.assign(n + 1, {});
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    depth[1] = 0;
    dfs(1, 1);

    for (int i = 1; i < LOG; i++)
    {
        for (int v = 1; v <= n; v++)
        {
            up[i][v] = up[i - 1][up[i - 1][v]];
        }
    }

    int q;
    cin >> q;
    while (q--)
    {
        ll x, y, a, b, k;
        cin >> x >> y >> a >> b >> k;

        bool ok = false;

        ll d0 = dist(a, b);
        if (k >= d0 && ((k - d0) % 2 == 0))
            ok = true;

        ll d1 = dist(a, x) + 1 + dist(y, b);
        if (k >= d1 && ((k - d1) % 2 == 0))
            ok = true;

        ll d2 = dist(a, y) + 1 + dist(x, b);
        if (k >= d2 && ((k - d2) % 2 == 0))
            ok = true;

        cout << (ok ? "YES" : "NO") << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while (t--)
        solve();

    return 0;
}