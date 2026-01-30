#include <bits/stdc++.h>
using namespace std;

static const long long NEG = -1e18;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
    {
        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        vector<long long> dp(k + 1, NEG);
        dp[0] = 0;

        for (int i = 0; i < n; i++)
        {
            vector<long long> ndp = dp;

            for (int c = 0; c <= k; c++)
            {
                if (dp[c] < 0)
                    continue;

                for (int x = 1; x <= a[i]; x++)
                {
                    if (c + x <= k)
                    {
                        ndp[c + x] = max(
                            ndp[c + x],
                            dp[c] + 1LL * x * (n - i));
                    }
                }
            }
            dp.swap(ndp);
        }

        long long ans = 0;
        for (int c = 0; c <= k; c++)
            ans = max(ans, dp[c]);

        cout << ans << "\n";
    }

    return 0;
}
