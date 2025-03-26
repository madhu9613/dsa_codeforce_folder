//its using priority queue


#include <bits/stdc++.h>
using namespace std;

void dijkstra(int n, vector<vector<pair<int, int>>> &adj, int src) {
    vector<int> dist(n, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    dist[src] = 0;
    pq.push({0, src}); // {distance, node}

    while (!pq.empty()) {
        int nodedistance = pq.top().first;
        int topnode = pq.top().second;
        pq.pop();

        if (nodedistance > dist[topnode]) continue;

        for (auto &[neighbor, weight] : adj[topnode]) {
            if (dist[topnode] + weight < dist[neighbor]) {
                dist[neighbor] = dist[topnode] + weight;
                pq.push({dist[neighbor], neighbor});
            }
        }
    }

    // Print shortest distances
    for (int i = 0; i < n; i++) {
        cout << "Shortest distance to node " << i << " is "
             << (dist[i] == INT_MAX ? -1 : dist[i]) << endl;
    }
}

int main() {
    int n ,m;
    cin>>n>>m;
    vector<vector<pair<int, int>>> adj(n);
    for(int i=0;i<m;i++)
    {
        int u,v,w;cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});

    }
    

    int src = 0;
    dijkstra(n, adj, src);

    return 0;
}
