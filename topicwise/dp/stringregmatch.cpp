//interview bit :>regex expression 2
//do it again]


#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve()
{
    string a, b;
    cin >> a >> b;
    int n = a.size();
    int m = b.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
    dp[0][0] = true;

    // Initialize pattern for empty string a
    for (int j = 2; j <= m; j++)
    {
        if (b[j - 1] == '*')
            dp[0][j] = dp[0][j - 2];
    }

    // Fill the DP table
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (b[j - 1] == a[i - 1] || b[j - 1] == '.')
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else if (b[j - 1] == '*')
            {
                dp[i][j] = dp[i][j - 2]; // Treat '*' and its preceding element as 0 occurrence
                if (b[j - 2] == a[i - 1] || b[j - 2] == '.')
                {
                    dp[i][j] = dp[i][j] || dp[i - 1][j]; // Treat it as multiple occurrences
                }
            }
        }
    }

    cout << (dp[n][m] ? 1 : 0) << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
