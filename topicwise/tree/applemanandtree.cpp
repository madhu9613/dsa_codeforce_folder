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

const int MAXN = 1e5 + 5;
int n, x[MAXN];
vi adj[MAXN];
int dp[MAXN][2];

void dfs(int v)
{
    dp[v][0] = 1;
    dp[v][1] = 0;

    for (int u : adj[v])
    {
        dfs(u);
        ll new0 = (1LL * dp[v][0] * (dp[u][0] + dp[u][1]) % MOD);
        ll new1 = (1LL * dp[v][1] * (dp[u][0] + dp[u][1]) % MOD + 
                   1LL * dp[v][0] * dp[u][1] % MOD) % MOD;
        dp[v][0] = new0;
        dp[v][1] = new1;
    }

    if (x[v]) {
        dp[v][1] = dp[v][0];
        dp[v][0] = 0;
    }
}


void solve()
{
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int p;
        cin >> p;
        
        adj[p].pb(i);
    }

    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }

    dfs(0);
    cout<<dp[0][1]<<endl;
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