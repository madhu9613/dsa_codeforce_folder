#include <bits/stdc++.h>
using namespace std;

template <typename T>
class graph {
public:
    map<T, vector<pair<T, int>>> adj;

    void addedges(T u, T v, int w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    void print() {
        for (auto &i : adj) {
            cout << i.first << " --> ";
            for (auto &j : i.second) {
                cout << "(" << j.first << ", " << j.second << ") ";
            }
            cout << endl;
        }
    }

    vector<int> shortestpath(T src) {
        set<pair<int, T>> st; // (distance, node)
        unordered_map<T, int> distance;

        // Initialize distances to infinity
        for (auto &node : adj) {
            distance[node.first] = INT_MAX;
        }

        distance[src] = 0;
        st.insert({0, src});

        while (!st.empty()) {
            auto top = *(st.begin());
            T topnode = top.second;
            int nodedistance = top.first;
            st.erase(st.begin());

            for (auto &neighbour : adj[topnode]) {
                if (nodedistance + neighbour.second < distance[neighbour.first]) {
                    auto record = st.find({distance[neighbour.first], neighbour.first});
                    if (record != st.end()) {
                        st.erase(record);
                    }
                    distance[neighbour.first] = nodedistance + neighbour.second;
                    st.insert({distance[neighbour.first], neighbour.first});
                }
            }
        }

        vector<int> result;
        for (auto &node : adj) {
            result.push_back(distance[node.first]);
        }

        return result;
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
    cout << "Enter source node: ";
    cin >> src;

    vector<int> distances = g.shortestpath(src);

    cout << "Shortest distances from node " << src << ":\n";
    for (int i = 0; i < n; i++) {
        cout << "Node " << i << ": " << (distances[i] == INT_MAX ? -1 : distances[i]) << endl;
    }

    return 0;
}
