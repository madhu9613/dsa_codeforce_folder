#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int MOD = 1e9 + 7;

vector<vector<int>> memo;
vector<char> cmd;
int n;

int f(int idx, int iden) {
    if (idx == n + 1) return 1; // base case: one valid way

    if (memo[idx][iden] != -1) return memo[idx][iden];

    ll ans = 0;
    if (cmd[idx] == 'f') {
        ans = f(idx + 1, iden + 1); // must indent
    } else {
        for (int k = 0; k <= iden; k++) {
            ans = (ans + f(idx + 1, k)) % MOD; // can dedent
        }
    }

    return memo[idx][iden] = ans % MOD;
}

void solve() {
    cin >> n;
    cmd.resize(n + 1);
    for (int i = 1; i <= n; i++) cin >> cmd[i];

    memo.assign(n + 1, vector<int>(n + 1, -1));
    cout << f(1, 0) % MOD << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
