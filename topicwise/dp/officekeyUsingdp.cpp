#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e18;

int main() {
    int n, k, p;
    cin >> n >> k >> p;

    vector<int> a(n + 1), b(k + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= k; ++i) cin >> b[i];

    sort(a.begin() + 1, a.end());
    sort(b.begin() + 1, b.end());

    // Initialize dp table
    vector<vector<ll>> dp(n + 1, vector<ll>(k + 1, INF));

    // Base case: 0 people assigned means 0 time
    for (int j = 0; j <= k; ++j) dp[0][j] = 0;

    // DP transition
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= k; ++j) {
            ll cost = abs(a[i] - b[j]) + abs(b[j] - p);
            dp[i][j] = min(dp[i][j - 1], max(dp[i - 1][j - 1], cost));
        }
    }

    cout << dp[n][k] << '\n';
    return 0;
}
