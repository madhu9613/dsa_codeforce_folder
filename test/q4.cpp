#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        bool linear = true;
        long long k = a[1] - a[0];
        for (int i = 1; i < n-1; i++) {
            if (a[i+1] - a[i] != k) {
                linear = false;
                break;
            }
        }

        if (!linear) {
            cout << "NO\n";
        } else {
            long long c_val = a[0] - k;
            long long n1 = n + 1;

            if (c_val < 0) {
                cout << "NO\n";
            } else if (c_val % n1 != 0) {
                cout << "NO\n";
            } else {
                long long y = c_val / n1;
                long long x = k + y;
                if (x >= 0) {
                    cout << "YES\n";
                } else {
                    cout << "NO\n";
                }
            }
        }
    }
    return 0;
}