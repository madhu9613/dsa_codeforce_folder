#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int tt;
    cin >> tt;
    while (tt--) {
        ull n, l, r, k;
        cin >> n >> l >> r >> k;

        if (n == 1) {
            // Single element: AND = XOR = value itself
            cout << l << "\n";
        }
        else if (n & 1) {
            // Odd n: use [l, l, ..., l]
            if (k <= n) cout << l << "\n";
            else cout << "-1\n";
        }
        else {
            if (n == 2) {
                // Special case: just two values can't make AND = XOR = 0 unless a & b = 0
                cout << "-1\n";
            }
            else {
                // Try to find x such that x >= l, x & l == 0
                ull x = l;
                while (true) {
                    bool found = true;
                    for (int i = 0; i < 64; i++) {
                        ull bit = 1ULL << i;
                        if ((l & bit) && (x & bit)) {
                            x += bit;
                            x &= ~(bit - 1);  // clear all lower bits
                            found = false;
                            break;
                        }
                    }
                    if (found) break;
                }

                if (x > r) {
                    cout << "-1\n";  // No such x in range
                }
                else {
                    // Output kth element of array: [l, l, ..., x, x]
                    if (k <= n - 2) cout << l << "\n";
                    else cout << x << "\n";
                }
            }
        }
    }

    return 0;
}
