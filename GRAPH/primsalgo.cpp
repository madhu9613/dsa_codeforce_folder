#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g) {
    // Step 1: Convert Edge List to Adjacency List
    unordered_map<int, vector<pair<int, int>>> adj;
    for (int i = 0; i < g.size(); i++) {
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // Since the graph is undirected
    }

    // Step 2: Initialize Required Arrays
    vector<int> key(n + 1, INT_MAX);  // To store minimum edge weight
    vector<bool> mst(n + 1, false);   // To track included nodes
    vector<int> parent(n + 1, -1);    // To store the MST

    key[1] = 0;  // Start from node 1

    // Step 3: Build MST using Prim’s Algorithm (Without Optimization)
    for (int i = 0; i < n - 1; i++) {  // Run for n-1 edges
        int mini = INT_MAX, u = -1;

        // Step 3.1: Find the minimum key node that is not in MST
        for (int v = 1; v <= n; v++) {
            if (!mst[v] && key[v] < mini) {
                mini = key[v];
                u = v;
            }
        }

        mst[u] = true; // Include in MST

        // Step 3.2: Update the key values for adjacent vertices
        for (auto neighbour : adj[u]) {
            int v = neighbour.first;
            int w = neighbour.second;

            if (!mst[v] && w < key[v]) {
                parent[v] = u;
                key[v] = w;
            }
        }
    }

    // Step 4: Construct the Resulting MST
    vector<pair<pair<int, int>, int>> mstEdges;
    for (int i = 2; i <= n; i++) {
        mstEdges.push_back({{parent[i], i}, key[i]});
    }

    return mstEdges;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<pair<int, int>, int>> edges(m);
    
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = {{u, v}, w};
    }

    vector<pair<pair<int, int>, int>> mst = calculatePrimsMST(n, m, edges);

    cout << "Edge   Weight\n";
    for (auto edge : mst) {
        cout << edge.first.first << " - " << edge.first.second << "   " << edge.second << "\n";
    }

    return 0;
}



