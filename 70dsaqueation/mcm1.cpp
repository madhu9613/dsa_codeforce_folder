#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define INF LLONG_MAX

pair<ll, string> mcm(const vi &a)
{
    int n = (int)a.size() - 1; // dims size = n+1
    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, 0));
    vector<vector<int>> split(n + 1, vector<int>(n + 1, 0));

    for (int len = 2; len <= n; ++len)
    {
        for (int i = 1; i + len - 1 <= n; i++)
        {
            int j = i + len - 1;
            dp[i][j] = INF;

            for (int k = i; k < j; k++)
            {
                ll cost = dp[i][k] + dp[k + 1][j] + 1LL * a[i - 1] * a[k] * a[j];
                if (cost < dp[i][j])
                {
                    dp[i][j] = cost;
                    split[i][j] = k;
                }
            }
        }
    }

    function<string(int, int)> build = [&](int i, int j) -> string
    {
        if (i == j)
            return "A" + to_string(i);
        int k = split[i][j];
        return "(" + build(i, k) + build(k + 1, j) + ")";
    };

    return {dp[1][n], build(1, n)};
}

void solve()
{
    int n;
    cin >> n;

    vi a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    auto res = mcm(a);
    cout << "Min multiplications: " << res.first << "\n";
    cout << "Optimal parenthesization: " << res.second << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--)
        solve();
    return 0;
}
