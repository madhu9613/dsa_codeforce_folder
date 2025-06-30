#include <bits/stdc++.h>
using namespace std;

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }

        long long sum_a = 0, sum_b = 0;
        for (int i = 0; i < n; i++) {
            sum_a += a[i];
            sum_b += b[i];
        }

        if (sum_a < sum_b) {
            cout << "NO" << endl;
            continue;
        }

        bool possible = true;
        for (int i = 0; i < n; i++) {
            if (a[i] < b[i]) {
                int diff = b[i] - a[i];
                for (int j = 0; j < n; j++) {
                    if (j != i) {
                        a[j] -= diff;  
                    }
                }
                a[i] += diff; 
            }
        }

        for (int i = 0; i < n; i++) {
            if (a[i] < b[i]) {
                possible = false;
                break;
            }
        }

        if (possible) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
