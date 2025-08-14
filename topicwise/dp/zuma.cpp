#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n + 2);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    vector<vector<int>> dp(n + 3, vector<int>(n + 3, 0));

    for (int len = 1; len <= n; len++) {
        for (int l = 1; l + len - 1 <= n; l++) {
            int r = l + len - 1;
            if (l == r) {
                dp[l][r] = 1;
            } else {
                dp[l][r] = 1 + dp[l + 1][r];

                if (a[l] == a[l + 1]) {
                    dp[l][r] = min(dp[l][r], 1 + dp[l + 2][r]);
                }

                for (int k = l + 2; k <= r; k++) {
                    if (a[l] == a[k]) {
                        dp[l][r] = min(dp[l][r], dp[l + 1][k - 1] + dp[k + 1][r]);
                    }
                }
            }
        }
    }

    cout << dp[1][n] << "\n";
}
