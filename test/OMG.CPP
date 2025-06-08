#include <bits/stdc++.h>
using namespace std;

const int INF = 2e9;

struct Edge {
    int to, weight;
};

int bfs(int n, int Wmin, const vector<vector<Edge>>& graph) {
    vector<int> maxEdge(n + 1, INF);
    queue<int> q;

    maxEdge[1] = 0;
    q.push(1);

    while (!q.empty()) {
        int u = q.front(); q.pop();

        for (auto& e : graph[u]) {
            if (e.weight >= Wmin) {
                int v = e.to;
                int w = max(maxEdge[u], e.weight);
                if (w < maxEdge[v]) {
                    maxEdge[v] = w;
                    q.push(v);
                }
            }
        }
    }

    return maxEdge[n];
}

int solve(int n, const vector<tuple<int, int, int>>& edges) {
    vector<vector<Edge>> graph(n + 1);
    int low = INF, high = 0;

    for (auto [u, v, w] : edges) {
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
        low = min(low, w);
        high = max(high, w);
    }

    int ans = INF;

    for (int wmin = low; wmin <= high; ++wmin) {
        int wmax = bfs(n, wmin, graph);
        if (wmax != INF) {
            ans = min(ans, wmin + wmax);
        }
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<tuple<int, int, int>> edges(m);
        for (int i = 0; i < m; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            edges[i] = {u, v, w};
        }

        cout << solve(n, edges) << '\n';
    }

    return 0;
}
