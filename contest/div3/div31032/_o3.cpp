#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), p(n), s(n);
        
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        p[0] = a[0];
        for (int i = 1; i < n; ++i) {
            p[i] = min(p[i - 1], a[i]);
        }

        s[n - 1] = a[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            s[i] = max(s[i + 1], a[i]);
        }

        string ans;
        for (int i = 0; i < n; ++i) {
            if (p[i] == a[i] || s[i] == a[i])
                ans += '1';
            else
                ans += '0';
        }

        cout << ans << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
