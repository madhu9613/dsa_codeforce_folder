#include <bits/stdc++.h>
using namespace std;

// Function to perform topological sorting using DFS
void topologicalSort(int node, vector<vector<pair<int, int>>> &adj, vector<bool> &visited, stack<int> &st) {
    visited[node] = true;
    for (auto &[neighbor, weight] : adj[node]) {
        if (!visited[neighbor])
            topologicalSort(neighbor, adj, visited, st);
    }
    st.push(node);
}

// Function to find the shortest path in a DAG
void shortestPathDAG(int n, vector<vector<pair<int, int>>> &adj, int src) {
    vector<bool> visited(n, false);
    stack<int> st;

    // Step 1: Topological Sorting
    for (int i = 0; i < n; i++)
        if (!visited[i])
            topologicalSort(i, adj, visited, st);

    // Step 2: Distance Array Initialization
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;

    // Step 3: Process nodes in topological order
    while (!st.empty()) {
        int node = st.top();
        st.pop();

        if (dist[node] != INT_MAX) {  // Only process if the node is reachable
            for (auto &[neighbor, weight] : adj[node]) {
                if (dist[node] + weight < dist[neighbor]) {
                    dist[neighbor] = dist[node] + weight;
                }
            }
        }
    }

    // Print the shortest distances
    for (int i = 0; i < n; i++) {
        cout << "Shortest distance to node " << i << " is " 
             << (dist[i] == INT_MAX ? -1 : dist[i]) << endl;
    }
}

int main() {
    int n = 6; // Number of nodes
    vector<vector<pair<int, int>>> adj(n);

    // Example: Adding edges in DAG {u, {v, weight}}
    adj[0] = {{1, 5}, {2, 3}};
    adj[1] = {{3, 6}, {2, 2}};
    adj[2] = {{4, 4}, {5, 2}, {3, 7}};
    adj[3] = {{5, 1}, {4, -1}};
    adj[4] = {{5, -2}};

    int src = 1; // Source node
    shortestPathDAG(n, adj, src);

    return 0;
}
