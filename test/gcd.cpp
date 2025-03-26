#include <bits/stdc++.h>
using namespace std;

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> S(m);
        for (int i = 0; i < m; ++i) {
            cin >> S[i];
        }

        if (m == 1 && n > 1) {
            cout << "-1\n";
            continue;
        }

        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            a[i] = S[m - (i % m) - 1];  
        }

        for (int i = 0; i < n; ++i) {
            cout << a[i] << " ";
        }
        cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
