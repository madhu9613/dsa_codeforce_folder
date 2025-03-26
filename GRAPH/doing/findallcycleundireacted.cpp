#include <bits/stdc++.h>
using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;
    set<vector<int>> uniqueCycles; // Store unique cycles

public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void dfs(int start, int node, vector<bool> &visited, vector<int> &path, int parent) {
        visited[node] = true;
        path.push_back(node);

        for (int neighbor : adj[node]) {
            if (neighbor == parent) continue; // Ignore the parent edge

            if (visited[neighbor]) {
                // Cycle detected: ensure it starts at the first occurrence of `neighbor`
                auto it = find(path.begin(), path.end(), neighbor);
                if (it != path.end() && *it == start) { 
                    vector<int> cycle(it, path.end());
                    sort(cycle.begin(), cycle.end()); // Normalize
                    uniqueCycles.insert(cycle);
                }
            } else {
                dfs(start, neighbor, visited, path, node);
            }
        }

        path.pop_back();
        visited[node] = false;
    }

    void findCycles() {
        vector<bool> visited(V, false);
        vector<int> path;

        for (int i = 0; i < V; i++) {
            dfs(i, i, visited, path, -1);
        }

        cout << "Total Cycles Found: " << uniqueCycles.size() << endl;
        for (auto cycle : uniqueCycles) {
            cout << "Cycle (Length " << cycle.size() << "): ";
            for (int node : cycle) cout << node << " ";
            cout << endl;
        }
    }
};

int main() {
    int V = 6, E = 7;
    Graph g(V);

    vector<pair<int, int>> edges = {
        {0, 1}, {1, 2}, {2, 3}, {3, 4},
        {4, 5}, {5, 0}, {1, 5}
    };

    for (auto [u, v] : edges)
        g.addEdge(u, v);

    g.findCycles();

    return 0;
}
