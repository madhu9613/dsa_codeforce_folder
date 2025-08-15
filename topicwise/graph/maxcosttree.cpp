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

ll a[MAXN];
vector<vector<int>> adj;
ll cost[MAXN];
ll ssum[MAXN];
ll totalsum;
void dfs1(int u, int p = -1, int d = 0)
{
    ssum[u] = a[u];
    cost[1] += d * a[u];
    for (int v : adj[u])
    {
        if (v == p)
            continue;
        dfs1(v, u, d + 1);
        ssum[u] += ssum[v];
    }
}

void dfs2(int u, int p = -1)
{
    for (int v : adj[u])
    {
        if (v == p)
            continue;
        cost[v] = cost[u] + (totalsum - 2 * ssum[v]);
        dfs2(v, u);
    }
}
void solve()
{
    int n;
    cin >> n;
    adj.resize(n + 1);
 
     totalsum=0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        totalsum+=a[i];
        adj[i].clear();
    }
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }


    cost[1]=0;
    dfs1(1);
    dfs2(1);

    ll ans=0;
    for(int i=1;i<=n;i++)
    {
    ans=max(ans,cost[i]);
    }
    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    while (t--)
        solve();
    return 0;
}