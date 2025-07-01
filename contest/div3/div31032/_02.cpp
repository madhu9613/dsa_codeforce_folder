#include <bits/stdc++.h>
using namespace std;

int solve() {
    int n, j, k;
    cin >> n >> j >> k;
    vector<int> a(n);
    int Maxi = INT_MIN;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
        Maxi = max(Maxi, a[i]);
    }

    // j is 1-based, so access a[j-1]
    if (a[j - 1] >= Maxi) {
        cout << "Yes" << endl;
    } else {
        if (k < 2) {
            cout << "No" << endl;
        } else {
            cout << "Yes" << endl;
        }
    }

    return 0;
}

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
