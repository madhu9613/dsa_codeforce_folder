#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    vector<int> dp(n, 0);
    int maxlen = 0;
    int countmax = 0;

    for (int i = 1; i < n; i++)
    {
        if (s[i] == ')')
        {
            if (s[i - 1] == '(')
            {
                dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
            }
            else if (i - dp[i - 1] - 1 >= 0 && s[i - dp[i - 1] - 1] == '(')
            {
                dp[i] = dp[i - 1] + 2;
                if (i - dp[i - 1] - 2 >= 0)
                {
                    dp[i] += dp[i - dp[i - 1] - 2];
                }
            }

            if (dp[i] > 0)
            {
                if (dp[i] > maxlen)
                {
                    maxlen = dp[i];
                    countmax = 1;
                }
                else if (dp[i] == maxlen)
                {
                    countmax++;
                }
            }
        }
    }

    cout << maxlen << " " << (maxlen== 0 ? 1 : countmax) << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
