#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool is_possible(vector<int>& a, vector<int>& b, int p, ll T) {
    int n = a.size();
    int k = b.size();
    int j = 0; // index in b
    for (int i = 0; i < n; ++i) {
        while (j < k && abs(a[i] - b[j]) + abs(b[j] - p) > T) {
            ++j;
        }
        if (j == k) return false;
        ++j; // assign this key to person i
    }
    return true;
}

int main() {
    int n, k, p;
    cin >> n >> k >> p;
    vector<int> a(n), b(k);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < k; ++i) cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    ll low = 0, high = 2e10, ans = 0;
    while (low <= high) {
        ll mid = (low + high) / 2;
        if (is_possible(a, b, p, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    cout << ans << '\n';
    return 0;
}
