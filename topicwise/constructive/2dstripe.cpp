#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<long long> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    long long p1 = 0, p2 = 0, p12 = 0;

    set<long long> s1, s2, s12;
    s1.insert(0);
    s2.insert(0);
    s12.insert(0);

    int ans = 0;

    for (int i = 0; i < n; i++) {
        p1 += a[i];
        p2 += b[i];
        p12 += a[i] + b[i];

        bool ok = false;

        if (s1.count(p1) || s2.count(p2) || s12.count(p12)) {
            ok = true;
        }

        if (a[i] == 0 || b[i] == 0) {
            ok = true;
        }

        if (ok) {
            ans++;
            p1 = p2 = p12 = 0;
            s1.clear(); s2.clear(); s12.clear();
            s1.insert(0);
            s2.insert(0);
            s12.insert(0);
        } else {
            s1.insert(p1);
            s2.insert(p2);
            s12.insert(p12);
        }
    }

    cout << ans << "\n";
}