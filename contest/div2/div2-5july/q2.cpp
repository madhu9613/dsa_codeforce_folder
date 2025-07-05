#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int px, py, qx, qy;
        cin >> px >> py >> qx >> qy;

        vector<int> a(n);
        long long S = 0, M = 0;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            S += a[i];
            M = max(M, 1LL * a[i]);
        }

        long long dx = px - qx;
        long long dy = py - qy;
        long long D_sq = dx * dx + dy * dy;
        long long S_sq = S * S;

        if (D_sq > S_sq) {
            cout << "No\n";
        } else {
            if (2 * M <= S) {
                cout << "Yes\n";
            } else {
                long long temp = 2 * M - S;
                if (D_sq >= temp * temp) {
                    cout << "Yes\n";
                } else {
                    cout << "No\n";
                }
            }
        }
    }

    return 0;
}
