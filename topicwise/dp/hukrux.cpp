#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
int n, m, k, x;
vector<vector<int>> adj;
vector<vector<vector<long long>>> dp;

void dfs(int u, int parent) {
    dp[u][0][0] = k - 1;     // u is not k, and not adjacent to k
    dp[u][1][0] = k-1;     // u is not k, but adjacent to k
    dp[u][2][1] = 1;         // u is k, use up 1 count

    for (int v : adj[u]) {
        if (v == parent) continue;

        dfs(v, u);

        vector<vector<long long>> temp(3, vector<long long>(x + 1, 0));

        for (int t1 = 0; t1 < 3; ++t1) {
            for (int c1 = 0; c1 <= x; ++c1) {
                if (dp[u][t1][c1] == 0) continue;

                for (int t2 = 0; t2 < 3; ++t2) {
                    if (t1 == 2 && t2 == 2) continue; // two adjacent k's not allowed
                    for (int c2 = 0; c2 + c1 <= x; ++c2) {
                        long long add = dp[u][t1][c1] * dp[v][t2][c2] % MOD;
                        temp[t1][c1 + c2] = (temp[t1][c1 + c2] + add) % MOD;
                    }
                }
            }
        }

        dp[u] = temp;
    }
}

int main() {
    cin >> n >> m;
    adj.resize(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v; cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cin >> k >> x;

    dp.assign(n, vector<vector<long long>>(3, vector<long long>(x + 2, 0)));

    dfs(0, -1);

    long long ans = 0;
    for (int t = 0; t < 3; ++t) {
        for (int c = 0; c <= x; ++c) {
            ans = (ans + dp[0][t][c]) % MOD;
        }
    }
    cout << ans << endl;
    return 0;
}


//incorrect one i will solve it letter