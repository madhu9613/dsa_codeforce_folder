#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> dp(N, vector<int>(M, 0));
    dp[0][0] = 1; // Start position

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (i - 2 >= 0 && j - 1 >= 0) dp[i][j] += dp[i - 2][j - 1];
            if (i - 1 >= 0 && j - 2 >= 0) dp[i][j] += dp[i - 1][j - 2];
        }
    }

    cout << dp[N-1][M-1] << endl; // Ways to reach bottom-right
    return 0;
}