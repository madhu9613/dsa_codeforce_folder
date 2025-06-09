#include <bits/stdc++.h>
#define int long long
#define inf 1e17
using namespace std;
vector<pair<int, int>> p;
int dp[10001][8];
int n;
int solve(int i, int mask)
{
    //  dp[i][mask]=dp[i][vitamin_mask] = min cost from index i with current vitamin set
    if (i >= n)
    {
        return inf;
    }
    if (mask == 7)
    {
        return 0; // all vitamin covered;
    }
    if (dp[i][mask] != -1)

    {
        return dp[i][mask];
    }

    // op1 :skip it;

    int skip = solve(i + 1, mask);

    // op2 : buy this juice:
    int buy = p[i].first + solve(i + 1, p[i].second | mask);

    return dp[i][mask] = min(skip, buy);
}

int tab()
{
    // dp[i][mask] = min cost to get vitamin `mask` from i to n-1
    // initialize with inf
    for (int i = 0; i <= n; i++)
    {
        for (int m = 0; m < 8; m++)
        {
            dp[i][m] = inf;
        }
    }

    // base case: from any i, if we already have all vitamins, cost = 0
    for (int i = 0; i <= n; i++)
    {
        dp[i][7] = 0;  // All vitamins collected
    }

    // fill table bottom-up
    for (int i = n - 1; i >= 0; i--)
    {
        for (int mask = 0; mask < 8; mask++)
        {
            int skip = dp[i + 1][mask];
            int buy = p[i].first + dp[i + 1][mask | p[i].second];

            dp[i][mask] = min(skip, buy);
        }
    }

    return dp[0][0];  // Starting from 0 with no vitamins
}

int32_t main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string s;
        int cost;
        cin >> cost >> s;
        int mask = 0;
        for (char &c : s)
        {
            if (c == 'A')
                mask |= 1 << 2;
            if (c == 'B')
                mask |= 1 << 1;
            if (c == 'C')
                mask |= 1 << 0;
        }

        p.push_back({cost, mask});
    }

    // memset(dp,-1,sizeof(dp));

    int ans = tab();
    cout << (ans == inf ? -1 : ans);

    return 0;
}
