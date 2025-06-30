#include <bits/stdc++.h>
#include <array>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        vector<array<int, 2>> rects(3);
        for (int i = 0; i < 3; i++) {
            cin >> rects[i][0] >> rects[i][1];
        }

        int total = 0;
        for (int i = 0; i < 3; i++) {
            total += rects[i][0] * rects[i][1];
        }

        int s = 0;
        while (s * s < total) {
            s++;
        }
        if (s * s != total) {
            cout << "NO" << endl;
            continue;
        }

        sort(rects.begin(), rects.end());
        bool found = false;
        do {
            int a0 = rects[0][0], a1 = rects[0][1];
            int b0 = rects[1][0], b1 = rects[1][1];
            int c0 = rects[2][0], c1 = rects[2][1];

            if (a1 == s && b1 == s && c1 == s) {
                if (a0 + b0 + c0 == s) {
                    found = true;
                }
            }
            if (found) break;

            if (a0 == s && b0 == s && c0 == s) {
                if (a1 + b1 + c1 == s) {
                    found = true;
                }
            }
            if (found) break;

            if (a1 == b1) {
                if (a0 + b0 == s) {
                    if (c0 == s && c1 == s - a1) {
                        found = true;
                    }
                }
            }
            if (found) break;

            if (a0 == b0) {
                if (a1 + b1 == s) {
                    if (c1 == s && c0 == s - a0) {
                        found = true;
                    }
                }
            }
            if (found) break;

            if (a1 == s) {
                if (b0 == s - a0 && c0 == s - a0) {
                    if (b1 + c1 == s) {
                        found = true;
                    }
                }
            }
            if (found) break;

            if (a0 == s) {
                if (b1 == s - a1 && c1 == s - a1) {
                    if (b0 + c0 == s) {
                        found = true;
                    }
                }
            }
            if (found) break;

        } while (next_permutation(rects.begin(), rects.end()));

        cout << (found ? "YES" : "NO") << endl;
    }
    return 0;
}