// Author: Madhujya Rajkhowa
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define all(x) (x).begin(), (x).end()
#define endl '\n'

const int MOD = 1e9 + 7;
const int INF = INT_MAX;

int n, desti;
vector<vector<int>> adj;
vector<int> visited;

bool dfs(int u) {
    if (u == desti) return true;
    visited[u] = 1;

    for (int &v : adj[u]) {
        if (!visited[v]) {
            if (dfs(v)) return true;
        }
    }
    return false;
}

void solve() {
    cin >> n >> desti;
    adj.assign(n + 1, {});      
    visited.assign(n + 1, 0);   

    for (int i = 1; i < n; i++) {
        int a; cin >> a;
        if (i + a <= n) adj[i].pb(i + a);
    }

    if (dfs(1)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    while (t--) solve();
    return 0;
}
