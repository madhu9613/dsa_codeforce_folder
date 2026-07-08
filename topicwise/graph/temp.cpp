#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;

        vector<int> a(n), b(m);
        for(int &x : a) cin >> x;
        for(int &x : b) cin >> x;

        // Step 1: check without magic
        int j = 0;
        for(int i = 0; i < n; i++) {
            if(j < m && a[i] >= b[j]) j++;
        }
        if(j == m) {
            cout << 0 << '\n';
            continue;
        }

        // Step 2: prefix
        vector<int> pref(n);
        j = 0;
        for(int i = 0; i < n; i++) {
            if(j < m && a[i] >= b[j]) j++;
            pref[i] = j;
        }

        // Step 3: suffix
        vector<int> suff(n);
        j = m - 1;
        for(int i = n - 1; i >= 0; i--) {
            if(j >= 0 && a[i] >= b[j]) j--;
            suff[i] = m - 1 - j;
        }

        int ans = INT_MAX;

        // Try each skipped position
        for(int i = 0; i < m; i++) {
            int needL = i-1;
            int needR = m - i - 2;

            // binary search for left position
            int l = -1;
            for(int pos = 0; pos < n; pos++) {
                if(pref[pos] >= needL) {
                    l = pos;
                    break;
                }
            }
            if(l == -1) continue;

            // check right
            if(l + 1 < n && suff[l + 1] >= needR) {
                ans = min(ans, b[i]);
            }
            else if(needR == 0) {
                ans = min(ans, b[i]);
            }
        }

        if(ans == INT_MAX) cout << -1 << '\n';
        else cout << ans << '\n';
    }
}