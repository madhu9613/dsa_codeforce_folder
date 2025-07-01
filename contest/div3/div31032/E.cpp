#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> f(n + 2, 0);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        f[a[i]]++;
    }

    int mex = 0;
    while (mex <= n && f[mex] > 0) {
        mex++;
    }

    vector<int> diff(n + 3, 0);

    int lft = f[0];
    int rgt = n;
    diff[lft]++;
    diff[rgt + 1]--;

    for (int m = 1; m <= mex; ++m) {
        int left_mex = f[m];
        int right_mex = n - m;
        if (left_mex <= right_mex) {
            diff[left_mex]++;
            diff[right_mex + 1]--;
        }
    }

    int c_mex = 0;
    for (int k = 0; k <= n; ++k) {
        c_mex += diff[k];
        cout << c_mex << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
