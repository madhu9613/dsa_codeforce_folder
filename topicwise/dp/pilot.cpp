#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll INF = 1e15;

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> pilot(n);
    for (int i = 0; i < n; i++) {
        cin >> pilot[i].first >> pilot[i].second;
    }

    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, INF));
    dp[0][0] = 0; 

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            if (j > 0)
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + pilot[i - 1].second);

            if (j + 1 <= n)
                dp[i][j] = min(dp[i][j], dp[i - 1][j + 1] + pilot[i - 1].first);
        }
    }

    cout << dp[n][0] << endl; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;

    while (t--) solve();
    return 0;
}
