
/**
 * @brief CYCLE DETECTION IN  GRAPH *
 *  is cycle present;
 */
#include <bits/stdc++.h>
using namespace std;
template <typename T>
class graph
{

// ---using bfs 
bool iscycle(T startnode, unordered_map<T, bool> &visited)
{
    unordered_map<T, T> parent; // To keep track of the parent of each node
    queue<T> q;
    q.push(startnode);
    parent[startnode] = -1; // Root node has no parent
    visited[startnode] = true;

    while (!q.empty())
    {
        T node = q.front();
        q.pop();

        for (auto neighbour : adj[node])
        {
            if (visited[neighbour] && neighbour != parent[node])
            {
                return true; // A cycle is detected
            }
            else if (!visited[neighbour])
            {
                q.push(neighbour);
                visited[neighbour] = true;
                parent[neighbour] = node; // Update the parent of the neighbor
            }
        }
    }
    return false;
}

// --- using dfs 

    bool iscycle_DFS(T node, T parent, unordered_map<T, bool> &visited)
    {
        visited[node] = true;
        for (auto neigh : adj[node])

        {
            if (!visited[neigh])
            {
                bool iscycledetected = iscycle_DFS(neigh, node, visited);
                if(iscycledetected)
                {
                    return true;
                }
            }
            else if(neigh != parent)
            {
                return true;
            }
        }
        return false;
    }

public:
    unordered_map<T, vector<T>> adj;

    void insert(T u, T v, bool d)
    {
        adj[u].push_back(v);
        if (!d)
        {
            adj[v].push_back(u);
        }
    }
    // -- using bfs
    bool iscyclepresent()
    {
        unordered_map<T, bool> visited;

        for (auto i : adj)
        {
            if (!visited[i.first])
            {
                bool ans = iscycle(i.first,  visited);
                if (ans == 1)
                {
                    return true;
                }
            }
        }

        return false;
    }

    // -- using dfs
    bool iscyclepresentDFS()
    {
        unordered_map<T, bool> visited;

        for (auto i : adj)
        {
            if (!visited[i.first])
            {
                bool ans = iscycle_DFS(i.first,-1, visited);
                if (ans == 1)
                {
                    return true;
                }
            }
        }

        return false;
    }
};

int main()
{
    graph<int> g;
    int n, m, d;
    cin >> n >> m >> d;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g.insert(u, v, d);
    }
    if (g.iscyclepresentDFS())
    {
        cout << "yes";
    }
    else
    {
        cout << "no";
    }
    return 0;
}
