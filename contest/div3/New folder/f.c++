#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;

vector<pair<int, int>> adj[MAXN];
int color[MAXN];

void solve() {
    int t;
    cin >> t;

    while (t--) {
        int n, q;
        cin >> n >> q;

        // Input colors
        for (int i = 1; i <= n; ++i) {
            cin >> color[i];
            adj[i].clear();
        }

        vector<int> u(n), v(n), c(n);
        for (int i = 0; i < n - 1; ++i) {
            cin >> u[i] >> v[i] >> c[i];
            adj[u[i]].emplace_back(v[i], c[i]);
            adj[v[i]].emplace_back(u[i], c[i]);
        }

        long long total_cost = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (color[u[i]] != color[v[i]])
                total_cost += c[i];
        }

        while (q--) {
            int node, new_color;
            cin >> node >> new_color;

            int old_color = color[node];
            if (old_color == new_color) {
                cout << total_cost << '\n';
                continue;
            }

            int sz = adj[node].size();
            for (int i = 0; i < sz; ++i) {
                int neighbor = adj[node][i].first;
                int edge_cost = adj[node][i].second;

              
                if (color[neighbor] != old_color)
                    ; 
                else
                    total_cost -= edge_cost;

                if (color[neighbor] != new_color)
                    ; 
                else
                    total_cost += edge_cost;
            }

            color[node] = new_color;
            cout << total_cost << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
