#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define all(x) (x).begin(), (x).end()
#define endl '\n'

vll x;

bool ispossible(int dist, int c) {
    int count = 1; 
    ll last_pos = x[0];

    for (int i = 1; i < x.size(); i++) {
        if (x[i] - last_pos >= dist) {
            count++;
            last_pos = x[i];
            if (count >= c) return true;
        }
    }
    return false;
}

void solve() {
    int n, c;
    cin >> n >> c;
    x.resize(n);
    for (int i = 0; i < n; i++) cin >> x[i];
    sort(all(x));

    int l = 1, r = 1e9, ans = 0;
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (ispossible(m, c)) {
            ans = m;
            l = m + 1; 
        } else {
            r = m - 1; 
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
