#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    int ones = 0;
    for (char c : s) {
        if (c == '1') ones++;
    }

    if (ones <= k) {
        cout << "Alice\n";
        return;
    }

    bool ok = false;
    for (int i = 0; i <= n - k; ++i) {
        bool all_zero = true;
        for (int j = i; j < i + k; ++j) {
            if (s[j] != '0') {
                all_zero = false;
                break;
            }
        }
        if (all_zero) {
            ok = true;
            break;
        }
    }

    if (ok || (2 * k <= n)) {
        cout << "Bob\n";
    } else {
        cout << "Alice\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
