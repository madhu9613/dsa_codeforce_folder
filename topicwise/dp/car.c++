#include <bits/stdc++.h>
using namespace std;


int main() {
    int v1, v2, t, d;
    cin >> v1 >> v2 >> t >> d;

    int max_v = max(v1, v2) + (t - 1) * d;
    vector<vector<int>> dp(t + 1, vector<int>(max_v + 1, -1));

    dp[1][v1] = v1;

    for (int i = 2; i <= t; ++i) {
        for (int v = 0; v <= max_v; ++v) {
            for (int delta = -d; delta <= d; ++delta) {
                int new_speed=v+delta;
                if(dp[i - 1][v]==-1) continue;
                if (new_speed >= 0 && new_speed <= max_v) {
                    dp[i][new_speed] = max(dp[i][new_speed], dp[i - 1][v] + new_speed);
                }
            }
        }
    }

    cout << dp[t][v2] << endl;
    return 0;
}
 