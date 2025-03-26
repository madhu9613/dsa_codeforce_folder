/**
 * kahnsalgo ;
 * topological sort using bfs algo
 * 1.. find indegree of nodes
 * 2.. push node with zero indegree to the queue
 * 3.. front of queue and find its adj list and do bfs and process the data
 *
 */
#include <bits/stdc++.h>
using namespace std;

template <typename T>
class graph
{
public:
    map<T, vector<T>> adj;

    void addedges(T u, T v, bool direction)
    {
        // directed: direction=1, undirected: direction=0
        adj[u].push_back(v);

        if (!direction)
        {
            adj[v].push_back(u);
        }
    }

    void printgraph()
    {
        for (auto i : adj)
        {
            cout << i.first << "-->";

            for (auto j : i.second)
            {
                cout << j << " ";
            }
            cout << endl;
        }
    }

    // Topological sorting using Kahn's Algorithm
    vector<T> topo_kahns()
    {
        map<T, int> indegree; // To store indegree of all nodes

        // Initialize indegree of all nodes to 0
        for (auto i : adj)
        {
            indegree[i.first] = 0;
        }

        // Calculate indegree of each node
        for (auto i : adj)
        {
            for (auto j : i.second)
            {
                indegree[j]++;
            }
        }

        queue<T> q;

        // Push all nodes with indegree 0 into the queue
        for (auto i : indegree)
        {
            if (i.second == 0)
            {
                q.push(i.first);
            }
        }

        vector<T> topo_order; // To store the topological order
        while (!q.empty())
        {
            T front = q.front();
            q.pop();
            topo_order.push_back(front);

            for (auto i : adj[front])
            {
                indegree[i]--;
                if (indegree[i] == 0)
                {
                    q.push(i);
                }
            }
        }
        return topo_order;
    }
    };


    int main()
    {
        int n, m, d;
        cin >> n >> m >> d;

        graph<int> g;

        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            g.addedges(u, v, d);
        }

        g.printgraph();

        vector<int> topo_order = g.topo_kahns();

        if (!topo_order.empty())
        {
            cout << "Topological Order: ";
            for (auto node : topo_order)
            {
                cout << node << " ";
            }
            cout << endl;
        }

        return 0;
    }
