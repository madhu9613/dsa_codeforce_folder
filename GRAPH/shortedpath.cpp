#include <bits/stdc++.h>
using namespace std;

template <typename T>
class graph {
public:
    map<T, vector<T>> adj;

    // Function to add edges to the graph
    void addedges(T u, T v, bool direction) {
        // directed direction = 1
        // undirected direction = 0
        adj[u].push_back(v);
        if (!direction) {
            adj[v].push_back(u);
        }
    }

    // Function to print the graph
    void printgraph() {
        for (auto i : adj) {
            cout << i.first << "-->";
            for (auto j : i.second) {
                cout << j << " ";
            }
            cout << endl;
        }
    }

    
    // Function to calculate the shortest path using BFS
    pair<vector<T>, int> shortestpath_using_bfs(T src, T dest) {
        unordered_map<T, bool> visited;  // To mark nodes as visited
        unordered_map<T, T> parent;     // To track the parent of each node
        unordered_map<T, int> distance; // To store distances
        queue<T> q;

        q.push(src);
        visited[src] = true;
        parent[src] = -1;
        distance[src] = 0; // Distance of source from itself is 0

        while (!q.empty()) {
            T f_node = q.front();
            q.pop();

            for (auto &neighbour : adj[f_node]) {
                if (!visited[neighbour]) {
                    visited[neighbour] = true;
                    parent[neighbour] = f_node;
                    distance[neighbour] = distance[f_node] + 1; // Increment distance
                    q.push(neighbour);
                }
            }
        }

        // Reconstruct the shortest path
        vector<T> shortestpath;
        T current = dest;
        shortestpath.push_back(current);

        while (current != src) {
            current = parent[current];
            shortestpath.push_back(current);
        }
        reverse(shortestpath.begin(), shortestpath.end());

        // Return the shortest path and its distance
        return {shortestpath, distance[dest]};
    }
};

int main() {
    int n, m, d;
    cin >> n >> m >> d;
    graph<int> g;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g.addedges(u, v, d);
    }

    // g.printgraph();

    int src, dest;
    cout << "Enter source and destination: ";
    cin >> src >> dest;

    auto result = g.shortestpath_using_bfs(src, dest);

    cout << "Shortest Path: ";
    for (auto i : result.first) {
        cout << i << " ";
    }
    cout << endl;

    cout << "Shortest Distance: " << result.second << endl;

    return 0;
}