// Author: Madhujya Rajkhowa
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vi vector<int>
#define all(x) (x).begin(), (x).end()
#define endl '\n'

int n, m;
vector<vector<int>> adj;
vector<bool> visited;
vector<int> result;

void bfs(int start) {
    queue<int> q;
    vector<int> component;
    
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int u = q.front(); q.pop();
        component.pb(u);
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }

    int size = component.size();
    for (int node : component) {
        result[node] = size;
    }
}

void solve() {
    cin >> n >> m;
    adj.assign(n + 1, {});
    visited.assign(n + 1, false);
    result.assign(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;
        vi f(k);
        for (int j = 0; j < k; j++) {
            cin >> f[j];
        }
        for (int j = 0; j < k - 1; j++) {
            adj[f[j]].pb(f[j + 1]);
            adj[f[j + 1]].pb(f[j]); 
        }
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            bfs(i);
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    while (t--) solve();
    return 0;
}
