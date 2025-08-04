// Author: Madhujya Rajkhowa
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define all(x) (x).begin(), (x).end()
#define endl '\n'

int n, m;
vector<vector<int>> adj;
vector<bool> visited;

void dfs(int u, ll &nodes, ll &edegs) {
    visited[u] = true;
    nodes++;
    edegs += adj[u].size(); 
    for (auto &v : adj[u]) {
        if (!visited[v]) {
            dfs(v, nodes, edegs); 
        }
    }
}

void solve() {
    cin >> n >> m;
    adj.resize(n + 1);
    visited.resize(n + 1, false);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            ll v = 0, e = 0;
            dfs(i, v, e);
            e = e / 2;
            ll total_e = v * (v - 1) / 2;
            if (e != total_e) {
                cout << "NO" << endl;
                return;
            }
        }
    }

    cout << "YES" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    while (t--) solve();
    return 0;
}
