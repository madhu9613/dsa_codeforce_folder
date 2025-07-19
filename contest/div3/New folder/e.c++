#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

void solve() {
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<ll> p(n), s(n), a(n);
        for (int i = 0; i < n; ++i) cin >> p[i];
        for (int i = 0; i < n; ++i) cin >> s[i];

        for (int i = 0; i < n; ++i)
            a[i] = lcm(p[i], s[i]);

        vector<ll> prefix(n), suffix(n);
        prefix[0] = a[0];
        for (int i = 1; i < n; ++i)
            prefix[i] = gcd(prefix[i - 1], a[i]);

        suffix[n - 1] = a[n - 1];
        for (int i = n - 2; i >= 0; --i)
            suffix[i] = gcd(suffix[i + 1], a[i]);

        bool found = true;
        for (int i = 0; i < n; ++i) {
            if (prefix[i] != p[i] || suffix[i] != s[i]) {
                found = false;
                break;
            }
        }

        cout << (found ? "YES\n" : "NO\n");
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
