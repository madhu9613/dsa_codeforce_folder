/*
shroted path  in directed acyclid graph and weighted graph....>>>
-------------------------------------------------------------------
1) find topological sort
2) using dfs update the distance vector;
input:
7 9                                         
0 1 5
0 2 3
1 2 2
1 3 6
2 3 7
2 4 4
2 5 2
3 4 -1
4 5 -2

 graph:
 0-->(1,5) (2,3) 
1-->(2,2) (3,6)
2-->(3,7) (4,4) (5,2)
3-->(4,-1)
4-->(5,-2)                              
*/
#include <bits/stdc++.h>
using namespace std;

template <typename T>
class graph {
    void topohelp(T node, unordered_map<T, bool>& visited, stack<T>& s) {
        visited[node] = true;
        for (auto neighbour : adj[node]) {
            if (!visited[neighbour.first]) { // `neighbour` is a pair
                topohelp(neighbour.first, visited, s);
            }
        }
        s.push(node);
    }

public:
    map<T, vector<pair<T, int>>> adj; // Adjacency list for a weighted graph

    // Add edges to the graph
    void addedges(T u, T v, int w) {
        adj[u].push_back({v, w});
    }

    // Print the adjacency list
    void print() {
        for (auto i : adj) {
            cout << i.first << "-->";
            for (auto j : i.second) {
                cout << "(" << j.first << "," << j.second << ") ";
            }
            cout << endl;
        }
    }

    // Topological sort
    vector<T> topologicalsort() {
        unordered_map<T, bool> visited;
        stack<T> s;
        vector<T> toposort;

        for (auto i : adj) {
            if (!visited[i.first]) {
                topohelp(i.first, visited, s);
            }
        }

        while (!s.empty()) {
            toposort.push_back(s.top());
            s.pop();
        }

        return toposort;
    }

    // Shortest path in a Directed Acyclic Graph (DAG)
    void shortestPath(T src, int n) {
        vector<T> topo = topologicalsort();

        // Initialize distances to infinity
        unordered_map<T, int> dist;
        for (int i = 0; i < n; i++) {
            dist[i] = INT_MAX;
        }
        dist[src] = 0;

        // Process nodes in topological order
        for (T node : topo) {
            if (dist[node] != INT_MAX) {
                for (auto neighbour : adj[node]) {
                    T v = neighbour.first;
                    int weight = neighbour.second;

                    if (dist[node] + weight < dist[v]) {
                        dist[v] = dist[node] + weight;
                    }
                }
            }
        }

        // Print shortest distances
        cout << "Shortest distances from source " << src << ":\n";
        for (int i = 0; i < n; i++) {
            if (dist[i] == INT_MAX) {
                cout << i << ": INF\n";
            } else {
                cout << i << ": " << dist[i] << "\n";
            }
        }
    }
};

int main() {
    graph<int> g;
    int n, m;
    cin >> n >> m; // Input the number of nodes and edges

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w; // Input edge details
        g.addedges(u, v, w);
    }

    g.print(); // Print the adjacency list of the graph

    int src;
    cin>>src;
    g.shortestPath(src, n);

    return 0;


}