#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int T, n, k, a[N];
void los()
{
    cin >> n >> k;
    vector<vector<int>> dp(k + 1, vector<int>(k + 1, -1e9));
    vector<int> pos(k + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    dp[0][0] = 0;
    int j = 1;
    for (int i = 1; i <= k; i++)
        for (; j <= n; j++)
            if (a[j] >= i)
            {
                pos[i] = j;
                break;
            }
    for (int i = 1; i <= k; i++)
        for (int j = 1; j <= i; j++)
            if (pos[j])
                for (int l = 0; l <= i - j; l++)
                    dp[i][j] = max(dp[i][j], dp[i - j][l] + (j - l) * (n - pos[j] + 1));
    int ans = 0;
    for (int i = 0; i <= k; i++)
        for (int j = 0; j <= k; j++)
            ans = max(ans, dp[i][j]);
    cout << ans << "\n";
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    for (cin >> T; T--;)
        los();
}