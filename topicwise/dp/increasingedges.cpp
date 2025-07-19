#include <bits/stdc++.h>
using namespace std;

typedef pair<int, pair<int, int>> Edge;

int main() {
    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = {w, {u, v}};
    }

    // Step 1: Sort edges by weight
    sort(edges.begin(), edges.end());

    vector<int> dp(n + 1, 0);         // dp[v] = max path length ending at v
    vector<int> dp_temp(n + 1, 0);    // temporary buffer to hold updates

    for (int i = 0; i < m;) {
        int j = i;
        // Step 2: Process group of same-weight edges
        while (j < m && edges[j].first == edges[i].first) {
            int u = edges[j].second.first;
            int v = edges[j].second.second;
            dp_temp[v] = max(dp_temp[v], dp[u] + 1);
            ++j;
        }
        // Step 3: Apply temp updates to dp
        for (int k = i; k < j; ++k) {
            int v = edges[k].second.second;
            dp[v] = max(dp[v], dp_temp[v]);
            dp_temp[v] = 0; // reset for next group
        }
        i = j;
    }

    // Step 4: Final answer = max path length over all nodes
    cout << *max_element(dp.begin(), dp.end()) << endl;
    return 0;
}
