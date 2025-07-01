#include <iostream>
#include <vector>
using namespace std;

void solve(int n) {
    vector<int> perm(n + 1, 0);
    vector<bool> visited(n + 1, false);

    for (int i = 2; i <= n; ++i) {
        if (!visited[i]) {
            vector<int> group;

            // Build group of unvisited multiples of i
            for (int j = i; j <= n; j += i) {
                if (!visited[j]) {
                    group.push_back(j);
                    visited[j] = true;  // ✅ mark visited immediately
                }
            }

            // Rotate the group
            int sz = group.size();
            for (int k = 0; k < sz; ++k) {
                perm[group[k]] = group[(k + 1) % sz];
            }
        }
    }

    // Only safe fixed point is p[1] = 1
    perm[1] = 1;

    // Output the permutation
    for (int i = 1; i <= n; ++i) {
        cout << perm[i] << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        solve(n);
    }

    return 0;
}
