#include<bits/stdc++.h>
using namespace std;

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];

        int ans = 0;
        int i = 0;

        while (i + k <= n) {
            bool found = true;
            for (int j = 0; j < k; ++j) {
                if (a[i + j] != 0) {
                    found = false;
                    break;
                }
            }

            if (found) {
                ++ans;
                i += k + 1; 
            } else {
                ++i; 
            }
        }

        cout << ans << '\n';
    }
    return 0;
}
