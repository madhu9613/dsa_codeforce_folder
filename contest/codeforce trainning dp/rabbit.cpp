#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string str;
    cin >> str;

    vector<int> dp(n, INT_MIN); // Use size n instead of n+1
    dp[0] = 0;  // Start at index 0 (1st cell)

    for (int i = 0; i < n; i++) {
        if (str[i] == 'w') {
            continue; // Skip swamp cells
        }

        int score = INT_MIN;
        if (i >= 1) score = max(score, dp[i - 1]);
        if (i >= 3) score = max(score, dp[i - 3]);
        if (i >= 5) score = max(score, dp[i - 5]);

        if (score != INT_MIN) {
            dp[i] = score + ((str[i] == '"') ? 1 : 0); // Fixed expression
        }
    }

    if (dp[n - 1] != INT_MIN) {
        cout << dp[n - 1] << endl;
    } else {
        cout << -1 << endl; // No valid path to the last cell
    }

    return 0;
}
