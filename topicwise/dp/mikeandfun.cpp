#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    
    vector<vector<int>> grid(n, vector<int>(m));
    vector<int> maxRow(n);  // max consecutive 1s for each row
    
    // Input grid
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }
    
    // Function to compute max streak of 1s in a row
    auto maxStreak = [&](vector<int> &row) {
        int res = 0, cnt = 0;
        for (int x : row) {
            if (x == 1) cnt++;
            else cnt = 0;
            res = max(res, cnt);
        }
        return res;
    };
    
    // Precompute max streaks
    for (int i = 0; i < n; ++i) {
        maxRow[i] = maxStreak(grid[i]);
    }
    
    // Process queries
    while (q--) {
        int i, j;
        cin >> i >> j;
        --i; --j; // 0-based indexing
        
        // Flip the cell
        grid[i][j] ^= 1;
        
        // Recalculate only for this row
        maxRow[i] = maxStreak(grid[i]);
        
        // Find the global max
        int ans = 0;
        for (int r = 0; r < n; ++r) {
            ans = max(ans, maxRow[r]);
        }
        
        cout << ans << '\n';
    }
    return 0;
}
