#include <iostream>
#include <vector>
#include <stack>
#include <limits.h>

using namespace std;

// Function for Topological Sorting
void topologicalSort(int node, vector<pair<int, int>> adj[], vector<bool> &visited, stack<int> &st) {
    visited[node] = true;
    for (auto it : adj[node]) {
        if (!visited[it.first])
            topologicalSort(it.first, adj, visited, st);
    }
    st.push(node);
}

// Function to find the shortest path in DAG
void shortestPath(int V, vector<pair<int, int>> adj[], int src) {
    vector<bool> visited(V, false);
    stack<int> st;

    // Step 1: Topological Sort
    for (int i = 0; i < V; i++)
        if (!visited[i])
            topologicalSort(i, adj, visited, st);

    // Step 2: Initialize distance array
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    // Step 3: Relaxation in topological order
    while (!st.empty()) {
        int node = st.top();
        st.pop();

        if (dist[node] != INT_MAX) {  // Process only reachable nodes
            for (auto it : adj[node]) {
                int v = it.first;
                int weight = it.second;
                if (dist[node] + weight < dist[v])
                    dist[v] = dist[node] + weight;
            }
        }
    }

    // Step 4: Print shortest distances
    cout << "Shortest distances from source " << src << ":\n";
    for (int i = 0; i < V; i++)
        cout << "Node " << i << ": " << (dist[i] == INT_MAX ? "INF" : to_string(dist[i])) << endl;
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<pair<int, int>> adj[V];

    cout << "Enter " << E << " edges (u v w):\n";
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});  // Directed Edge
    }

    int source;
    cout << "Enter source vertex: ";
    cin >> source;

    shortestPath(V, adj, source);

    return 0;
}

// Input
// 5 6
// 0 1 2        
// 0 3 6
// 1 3 8

// 1 3 3    
// 1 4 5    
// 1 2 4

