#include <bits/stdc++.h>
using namespace std;

const int MAX_T = 105;
const int MAX_V = 205;

int dp[MAX_T][MAX_V];

int main() {
    int v1, v2, t, d;
    cin >> v1 >> v2 >> t >> d;

    memset(dp, -1, sizeof(dp));
    dp[1][v1] = v1;

    for (int i = 2; i <= t; ++i) {
        for (int v = 0; v <= 200; ++v) {
            for (int delta = -d; delta <= d; ++delta) {
                int prev_v = v - delta;
                if (prev_v >= 0 && prev_v <= 200 && dp[i - 1][prev_v] != -1) {
                    dp[i][v] = max(dp[i][v], dp[i - 1][prev_v] + v);
                }
            }
        }
    }

    cout << dp[t][v2] << endl;
    return 0;
}
