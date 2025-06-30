#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m));
        int maxi = 0;

        // Read matrix and track global max
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j) {
                cin >> a[i][j];
                maxi = max(maxi, a[i][j]);
            }

        // Store all (i,j) where a[i][j] == global_max
        vector<pair<int, int>> pos;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (a[i][j] == maxi)
                    pos.emplace_back(i, j);

        // Try each possible row to reduce
        bool can_reduce = false;
        for (int r = 0; r < n && !can_reduce; ++r) {
            unordered_set<int> cols;
            for (auto &[i, j] : pos) {
                if (i != r) {
                    cols.insert(j);
                    if (cols.size() > 1) break;
                }
            }
            if (cols.size() <= 1)
                can_reduce = true;
        }

        cout << (can_reduce ? maxi - 1 : maxi) << '\n';
    }

    return 0;
}
