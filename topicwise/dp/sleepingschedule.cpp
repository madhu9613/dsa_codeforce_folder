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
// vova will sleep exectly n times; for ith time he will sleep exevly ai hours form time he woke up
void solve()
{
    int n, h, l, r;
    cin >> n >> h >> l >> r;
    vi a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    auto good = [&](int t)
    {
        return (l <= t && t <= r) ? 1 : 0;
    };

    vector<vector<int>> dp(n + 1, vector<int>(h, -INF));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int t = 0; t < h; t++)
        {
            if (dp[i - 1][t] == -INF)
            {
                continue;
            }
            int t1 = (t + a[i-1]) % h;
            dp[i][t1] = max(dp[i][t1], dp[i - 1][t] + good(t1));

            int t2 = (t + a[i-1] - 1) % h;
            dp[i][t2] = max(dp[i][t2], dp[i - 1][t] + good(t2));
        }
    }

    int ans = 0;
    for (int t = 0; t < h; t++)
    {
        ans = max(ans, dp[n][t]);
    }
    cout << ans << endl;
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