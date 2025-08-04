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

void solve()
{
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++)
    {
        int n, w;
        cin >> n >> w;
        vi b(n);
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }

        vector<vector<int>> dp(n + 1, vector<int>(w + 1, 0));

        for (int j = 0; j <= w; j++)
        {
            if (b[0] <= j)
                dp[1][j] = b[0];
        }

        for (int i = 2; i <= n; i++)
        {
            for (int j = 0; j <= w; j++)
            {
                dp[i][j] = dp[i - 1][j];

                if (j >= b[i - 1])
                {
                    dp[i][j] = max(dp[i][j], dp[i - 2][j - b[i - 1]] + b[i - 1]);
                }
            }
        }

        int res = 0;
        for (int j = 0; j <= w; j++)
        {
            res = max(res, dp[n][j]);
        }

        cout << "Scenario #" << t << ": " << res << endl;
    }
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
