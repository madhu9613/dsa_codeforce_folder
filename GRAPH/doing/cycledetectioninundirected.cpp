#include <bits/stdc++.h>
using namespace std;

class Graph {
    int V;
    unordered_map<int, vector<int>> adj;

public:
    Graph(int V) {
        this->V = V;
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // 1. DFS Traversal
    void DFSUtil(int node, unordered_set<int> &visited) {
        visited.insert(node);
        cout << node << " ";
        for (auto &neighbor : adj[node]) {
            if (!visited.count(neighbor))
                DFSUtil(neighbor, visited);
        }
    }

    void DFS(int start) {
        unordered_set<int> visited;
        cout << "DFS Traversal: ";
        DFSUtil(start, visited);
        cout << endl;
    }

    // 2. BFS Traversal
    void BFS(int start) {
        queue<int> q;
        unordered_set<int> visited;
        q.push(start);
        visited.insert(start);

        cout << "BFS Traversal: ";
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cout << node << " ";

            for (auto &neighbor : adj[node]) {
                if (!visited.count(neighbor)) {
                    q.push(neighbor);
                    visited.insert(neighbor);
                }
            }
        }
        cout << endl;
    }

    // 3. Cycle Detection (Using DFS)
    bool isCyclicDFS(int node, int parent, unordered_set<int> &visited) {
        visited.insert(node);
        for (auto &neighbor : adj[node]) {
            if (!visited.count(neighbor)) {
                if (isCyclicDFS(neighbor, node, visited)) return true;
            } else if (neighbor != parent) {
                return true;
            }
        }
        return false;
    }

    bool detectCycleDFS() {
        unordered_set<int> visited;
        for (auto &entry : adj) {
            if (!visited.count(entry.first)) {
                if (isCyclicDFS(entry.first, -1, visited)) {
                    return true;
                }
            }
        }
        return false;
    }

    // 4. Cycle Detection (Using BFS)
    bool detectCycleBFS() {
        unordered_set<int> visited;
        for (auto &entry : adj) {
            if (!visited.count(entry.first)) {
                queue<pair<int, int>> q;
                q.push({entry.first, -1});
                visited.insert(entry.first);

                while (!q.empty()) {
                    int node = q.front().first;
                    int parent = q.front().second;
                    q.pop();

                    for (auto &neighbor : adj[node]) {
                        if (!visited.count(neighbor)) {
                            visited.insert(neighbor);
                            q.push({neighbor, node});
                        } else if (neighbor != parent) {
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }

    // 5. Connected Components Count
    int countConnectedComponents() {
        unordered_set<int> visited;
        int count = 0;

        for (auto &entry : adj) {
            if (!visited.count(entry.first)) {
                count++;
                DFSUtil(entry.first, visited);
            }
        }
        return count;
    }

    // 6. Shortest Path using BFS (Unweighted Graph)
    vector<int> shortestPath(int src) {
        vector<int> dist(V, -1);
        queue<int> q;
        q.push(src);
        dist[src] = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (auto &neighbor : adj[node]) {
                if (dist[neighbor] == -1) {
                    dist[neighbor] = dist[node] + 1;
                    q.push(neighbor);
                }
            }
        }
        return dist;
    }

    // 7. Bridges in Graph (Tarjan’s Algorithm)
    void bridgeUtil(int u, vector<int> &disc, vector<int> &low, int &time, int parent, vector<pair<int, int>> &bridges) {
        disc[u] = low[u] = ++time;

        for (auto v : adj[u]) {
            if (disc[v] == -1) {
                bridgeUtil(v, disc, low, time, u, bridges);
                low[u] = min(low[u], low[v]);

                if (low[v] > disc[u]) {
                    bridges.push_back({u, v});
                }
            } else if (v != parent) {
                low[u] = min(low[u], disc[v]);
            }
        }
    }

    vector<pair<int, int>> findBridges() {
        vector<int> disc(V, -1), low(V, -1);
        vector<pair<int, int>> bridges;
        int time = 0;

        for (int i = 0; i < V; i++) {
            if (disc[i] == -1) {
                bridgeUtil(i, disc, low, time, -1, bridges);
            }
        }
        return bridges;
    }

    // 8. Articulation Points (Tarjan’s Algorithm)
    void APUtil(int u, vector<int> &disc, vector<int> &low, int &time, int parent, unordered_set<int> &AP) {
        disc[u] = low[u] = ++time;
        int children = 0;

        for (auto v : adj[u]) {
            if (disc[v] == -1) {
                children++;
                APUtil(v, disc, low, time, u, AP);
                low[u] = min(low[u], low[v]);

                if (parent == -1 && children > 1) AP.insert(u);
                if (parent != -1 && low[v] >= disc[u]) AP.insert(u);
            } else if (v != parent) {
                low[u] = min(low[u], disc[v]);
            }
        }
    }

    unordered_set<int> findArticulationPoints() {
        vector<int> disc(V, -1), low(V, -1);
        unordered_set<int> AP;
        int time = 0;

        for (int i = 0; i < V; i++) {
            if (disc[i] == -1) {
                APUtil(i, disc, low, time, -1, AP);
            }
        }
        return AP;
    }

    //detect all cycle present in the graph and print the all cycles
    void findCyclesDFS(int node,int parent,vector<bool> visited,vector<int>&path,set<string> &uniquecycles)
    {
        //dfs;
        visited[node]=true;
        path.push_back(node);
        for(int neighbour:adj[node])
        {
            if(!visited[neighbour])
            {//if its not visited yet do dfs for it

                findCyclesDFS(neighbour,node,visited,path,uniquecycles);
            }
            else if(neighbour!=parent){

                //its cyclic case means cycle detected
                auto it=find(path.begin(),path.end(),neighbour); //begining of the cycle;
                if(it!=path.end())
                {
                    vector<int> cycle(it,path.end());
                    sort(cycle.begin(),cycle.end());
                    string Cyclicpath="";
                    for(int x:cyle)
                    {
                        Cyclicpath+=to_string(x)+",";

                    }
                    cout<<Cyclicpath<<endl;
                }
            }
        }
    }

     
    void findAllCycles() {
        vector<bool> visited(V, false);
        vector<int> path;
        set<string> uniqueCycles;

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                findCyclesDFS(i, -1, visited, path, uniqueCycles);
            }
        }
    }


};

int main() {
    int V, E;
    cin >> V >> E;

    Graph g(V);

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    g.DFS(1);
    g.BFS(1);
    cout << "Cycle (DFS): " << g.detectCycleDFS() << endl;
    cout << "Cycle (BFS): " << g.detectCycleBFS() << endl;
    cout << "Connected Components: " << g.countConnectedComponents() << endl;

    vector<int> dist = g.shortestPath(1);
    cout << "Shortest Path from 1: ";
    for (int d : dist) cout << d << " ";
    cout << endl;

    vector<pair<int, int>> bridges = g.findBridges();
    cout << "Bridges: ";
    for (auto &b : bridges) cout << "(" << b.first << "," << b.second << ") ";
    cout << endl;

    unordered_set<int> AP = g.findArticulationPoints();
    cout << "Articulation Points: ";
    for (auto &ap : AP) cout << ap << " ";
    cout << endl;

    return 0;
}
