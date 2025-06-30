#include<bits/stdc++.h>

using namespace std;

bool canTransform(vector<int>& a, vector<int>& b) {
    if (accumulate(a.begin(), a.end(), 0) != accumulate(b.begin(), b.end(), 0)) {
        return false;
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int n = a.size(), m = b.size();
    
    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
    
    dp[0][0] = true;
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            }
            if (i > 1 && abs(a[i - 1] - a[i - 2]) <= 1 && dp[i - 2][j - 1]) {
                dp[i][j] = true;
            }
        }
    }
    
    return dp[n][m];
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<int> a(n), b(m);

        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < m; i++) cin >> b[i];

        if (canTransform(a, b)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}
