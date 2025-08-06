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

// rule of coloring
//  the vertex and its child cannot have the same color,
//  if a vertex has two children, then they must have different colors.
//   red ->0
//   green->1
//   blue->2
const int MAXN = 10005;
vector<int> adj[MAXN];
int node_id = 0;
string s;
int pos = 0;

int dp1[MAXN][3];
int dp2[MAXN][3];

int buildtree()
{
    int curr = node_id++;
    char type = s[pos++];
    if (type == '0')
    {
        return curr;
    }
    else if (type == '1')
    {
        int child = buildtree();
        adj[curr].pb(child);
        return curr;
    }
    else
    {
        int left = buildtree();
        int right = buildtree();
        adj[curr].pb(left);
        adj[curr].pb(right);
        return curr;
    }
}

void dfs(int u)
{
    if (adj[u].empty())
    {
        // if c==1 means green count is 1;
        for (int c = 0; c < 3; ++c)
        {
            dp1[u][c] = (c == 1 ? 1 : 0);
            dp2[u][c] = (c == 1 ? 1 : 0);
        }
        return;
    }

    for (int v : adj[u])
    {
        dfs(v);
    }

    for (int c = 0; c < 3; ++c)
    {
        int add = (c == 1 ? 1 : 0);
        if (adj[u].size() == 1)
        {
            int child = adj[u][0];
            dp1[u][c] = INT_MAX;
            dp2[u][c] = INT_MIN;
            for (int cc = 0; cc < 3; ++cc)
            {
                if (cc == c)
                    continue;
                dp1[u][c] = min(dp1[u][c], dp1[child][cc] + add);
                dp2[u][c] = max(dp2[u][c], dp2[child][cc] + add);
            }
        }
        else
        {

            int left = adj[u][0];
            int right = adj[u][1];

            dp1[u][c] = INT_MAX;
            dp2[u][c] = INT_MIN;
            for (int cl = 0; cl < 3; cl++)
            {
                if (cl == c)
                    continue;
                for (int cr = 0; cr < 3; cr++)
                {
                    if (cl == cr || cr == c)
                    {
                        continue;
                    }
                    int minval = dp1[left][cl] + dp1[right][cr] + add;
                    int maxval = dp2[left][cl] + dp2[right][cr] + add;

                    dp1[u][c] = min(dp1[u][c], minval);
                    dp2[u][c] = max(dp2[u][c], maxval);
                }
            }
        }
    }
}
void solve()
{
    cin >> s;
    node_id = 0;
    pos = 0;
    for (int i = 0; i < MAXN; ++i)
        adj[i].clear();
    int root = buildtree();
    dfs(root);

    int ming = min({dp1[root][0], dp1[root][1], dp1[root][2]});

    int maxg = max({dp2[root][0], dp2[root][1], dp2[root][2]});
    cout << maxg << " " << ming << endl;
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


///it was a very good queation :>need to review it ;