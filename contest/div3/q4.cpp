#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < n; ++i) cin >> b[i];

        vector<pair<int, int>> ops;

        // Step 1: Swap if a[i] > b[i]
        for (int i = 0; i < n; ++i) {
            if (a[i] > b[i]) {
                swap(a[i], b[i]);
                ops.push_back({3, i + 1});
            }
        }

        // Step 2: Sort a using bubble sort, record operations
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < n - 1 - i; ++j) {
                if (a[j] > a[j + 1]) {
                    swap(a[j], a[j + 1]);
                    ops.push_back({1, j + 1});
                }
            }
        }

        // Step 3: Sort b using bubble sort, record operations
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < n - 1 - i; ++j) {
                if (b[j] > b[j + 1]) {
                    swap(b[j], b[j + 1]);
                    ops.push_back({2, j + 1});
                }
            }
        }

        // Output result
        cout << ops.size() << "\n";
        for (auto [type, index] : ops) {
            cout << type << " " << index << "\n";
        }
    }

    return 0;
}
