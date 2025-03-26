/*
WELCOME TO
BRETH FIRST SEARCH :BFS
also try to disconnected graph


YOU ARE GIVEN
*/
#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Graph {
    // Helper for DFS traversal
    vector<T> dfsHelper(T startNode, unordered_map<T, bool> &visited) {
        vector<T> component; // To store DFS traversal
        stack<T> s;          // Stack for DFS
        s.push(startNode);

        while (!s.empty()) {
            T node = s.top();
            s.pop();

            // If already visited, skip
            if (visited[node]) continue;

            visited[node] = true;
            component.push_back(node);

            for (auto neighbour : adj[node]) {
                if (!visited[neighbour]) {
                    s.push(neighbour);
                }
            }
        }
        return component;
    }

    // Helper for BFS traversal
    vector<T> bfsHelper(T startNode, unordered_map<T, bool> &visited) {
        vector<T> component; // To store BFS traversal
        queue<T> q;
        q.push(startNode);
        visited[startNode] = true;

        while (!q.empty()) {
            T node = q.front();
            q.pop();
            component.push_back(node);

            for (auto neighbour : adj[node]) {
                if (!visited[neighbour]) {
                    q.push(neighbour);
                    visited[neighbour] = true;
                }
            }
        }
        return component;
    }

public:
    map<T, vector<T>> adj;

    void addEdge(T u, T v, bool direction) {
        // Directed: direction = 1, Undirected: direction = 0
        adj[u].push_back(v);
        if (!direction) {
            adj[v].push_back(u);
        }
    }

    void print() {
        for (auto i : adj) {
            cout << i.first << " --> ";
            for (auto j : i.second) {
                cout << j << " ";
            }
            cout << endl;
        }
    }

    vector<T> BFS() {
        unordered_map<T, bool> visited;
        vector<T> result;

        for (auto i : adj) {
            if (!visited[i.first]) {
                vector<T> component = bfsHelper(i.first, visited);
                result.insert(result.end(), component.begin(), component.end());
            }
        }
        return result;
    }

    vector<T> DFS() {
        unordered_map<T, bool> visited;
        vector<T> result;

        for (auto i : adj) {
            if (!visited[i.first]) {
                vector<T> component = dfsHelper(i.first, visited);
                result.insert(result.end(), component.begin(), component.end());
            }
        }
        return result;
    }
};

int main() {
    Graph<int> g;
    int n, m, d;
    cin >> n >> m >> d; // Number of nodes, edges, and direction (0/1)
    int u, v;

    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        g.addEdge(u, v, d);
    }

    cout << "Adjacency List:" << endl;
    g.print();

    cout << "\nBFS Traversal:" << endl;
    vector<int> bfsTraversal = g.BFS();
    for (int node : bfsTraversal) {
        cout << node << " ";
    }

    cout << "\n\nDFS Traversal:" << endl;
    vector<int> dfsTraversal = g.DFS();
    for (int node : dfsTraversal) {
        cout << node << " ";
    }

    return 0;
}
