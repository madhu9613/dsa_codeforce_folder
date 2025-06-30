#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> a(n, vector<int>(m));
        int max_val = 0;

        // Store matrix and find max
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j) {
                cin >> a[i][j];
                max_val = max(max_val, a[i][j]);
            }

        // Store all positions of max elements
        vector<pair<int, int>> max_pos;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (a[i][j] == max_val)
                    max_pos.push_back({i, j});

        // Try every (r, c) from max_pos
        bool can_reduce = false;
        for (auto [r, c] : max_pos) {
            bool ok = true;
            for (auto [x, y] : max_pos) {
                if (x != r && y != c) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                can_reduce = true;
                break;
            }
        }

        // Output answer
        if (can_reduce)
            cout << max_val - 1 << '\n';
        else
            cout << max_val << '\n';
    }

    return 0;
}
