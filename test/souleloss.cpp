#include <bits/stdc++.h>
using namespace std;

int maxMatchesWithOneRemoval(const vector<int>& a, const vector<int>& b) {
    int n = a.size();
    vector<int> prefix(n, 0), suffix(n, 0);

    // Build prefix match counts
    for (int i = 0; i < n; ++i) {
        if (a[i] == b[i])
            prefix[i] = 1;
        if (i > 0)
            prefix[i] += prefix[i - 1];
    }

    // Build suffix match counts
    for (int i = n - 1; i >= 0; --i) {
        if (a[i] == b[i])
            suffix[i] = 1;
        if (i < n - 1)
            suffix[i] += suffix[i + 1];
    }

    // Initial answer = no removal
    int ans = prefix[n - 1];

    // Try removing each index
    for (int i = 0; i < n; ++i) {
        int left = (i > 0) ? prefix[i - 1] : 0;
        int right = (i < n - 1) ? suffix[i + 1] : 0;
        ans = max(ans, left + right);
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n), b(n);
        for (int& x : a) cin >> x;
        for (int& x : b) cin >> x;

        cout << maxMatchesWithOneRemoval(a, b) << '\n';
    }

    return 0;
}
