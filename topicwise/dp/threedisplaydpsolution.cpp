// Author: Madhujya Rajkhowa
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define INF LLONG_MAX

void solve()
{
    int n;
    cin >> n;
    vll fs(n + 1), cost(n + 1);
    for (int i = 1; i <= n; i++) cin >> fs[i];
    for (int i = 1; i <= n; i++) cin >> cost[i];

    // dp[i][k] = min cost to reach index i with k elements in increasing order ending at i
    vector<vector<ll>> dp(n + 1, vector<ll>(4, INF));

    // Base case: pick one element at index i
    for (int i = 1; i <= n; i++) dp[i][1] = cost[i];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            if (fs[j] < fs[i])
            {
                for (int k = 2; k <= 3; k++)
                {
                    if (dp[j][k - 1] != INF)
                        dp[i][k] = min(dp[i][k], dp[j][k - 1] + cost[i]);
                }
            }
        }
    }

    ll ans = INF;
    for (int i = 1; i <= n; i++)
    {
        ans = min(ans, dp[i][3]);
    }

    cout << (ans == INF ? -1 : ans) << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
