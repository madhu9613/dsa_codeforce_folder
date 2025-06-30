#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int ans = 0;
        
        if (n % 2 == 0) { // n is even
            if (n % (k - 1) == 0) {
                ans = n / (k - 1);
            } else {
                ans = (n / (k - 1)) + 1;
            }
        } else { // n is odd
            n -= k; // Remove one k to make it even
            ans++; // Count this subtraction

            if (n > 0) { // Now handle the remaining n (which is even)
                if (n % (k - 1) == 0) {
                    ans += n / (k - 1);
                } else {
                    ans += (n / (k - 1)) + 1;
                }
            }
        }
        cout << ans << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
