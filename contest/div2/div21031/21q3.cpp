#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        int64 m;
        cin >> n >> m;

        bool found = false;
        int R = -1;
        int64 base, rem;
        for (int r = 1; r <= n; ++r) {
            base = int64(r) * (r + 1) / 2;
            if (base > m) break;
            rem = m - base;
            int64 L = n - r;

            if (L <= rem && rem <= L * int64(r)) {
                R = r;
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "-1\n";
            continue;
        }

        vector<pair<int, int>> edges;
        for (int x = R; x > 1; --x) {
            edges.emplace_back(x, x - 1);
        }

        int64 L = n - R;
        int64 E = rem - L; 
        for (int v = R + 1; v <= n; ++v) {
            int64 extra = min(int64(R - 1), E);
            E -= extra;
            int to = int(1 + extra);
            edges.emplace_back(to, v);
        }

        assert(E == 0);

        cout << R << "\n";
        for (auto &e : edges) {
            cout << e.first << " " << e.second << "\n";
        }
    }

    return 0;
}
