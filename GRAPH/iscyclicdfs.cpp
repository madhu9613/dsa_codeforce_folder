#include <bits/stdc++.h>
using namespace std;
template <typename T>
class graph
{

// ----------undirected graph 

    bool dfscycle(T node, unordered_map<T, bool> &visited)
    {
        stack<T> s;
        unordered_map<T, T> parent;
        parent[node] = -1;
        visited[node] = true;
        s.push(node);

        while (!s.empty())
        {
            T node = s.top();
            s.pop();

            for (auto neighbour : adj[node])
            {
                if (visited[neighbour] && neighbour != parent[node])

                {
                    return true; // it is a cyclic;
                }
                else if (!visited[neighbour])
                {
                    s.push(neighbour);
                    parent[neighbour] = node;
                    visited[neighbour] = true;
                }
            }
        }

        return false;
    }


    // ------------------------- 
      bool directed_cycle(T node, unordered_map<T, bool> &visited,
                        unordered_map<T, bool> &dfsvisited)
    {

        visited[node] = true;
        dfsvisited[node] = true;
        for (auto neighbour : adj[node])
        {
            if (!visited[neighbour])
            {
                bool ans = directed_cycle(neighbour, visited, dfsvisited);
                if (ans)
                {
                    return true;
                }
            }
            else if (dfsvisited[neighbour])
            {
                return true;
            }
        }
        dfsvisited[node]=false;
        return false;
    }



public:
    // map<T,vector<T> > adj; //for sorted order if not required used unordered map and unodered map take 0(1) for ins and deletion
    unordered_map<T, vector<T>> adj;
    void insert(T u, T v, bool d)
    {
        adj[u].push_back(v);
        if (!d)
        {
            adj[v].push_back(u);
        }
    }
    void print()
    {
        for (auto i : adj)
        {
            cout << i.first << "--->";
            for (auto j : i.second)
            {
                cout << j << " ";
            }
            cout << endl;
        }
    }

    bool iscyclic_dfs()

    {
        unordered_map<T, bool> visited;
        for (auto i : adj)
        {
            if (!visited[i.first]) // i.first is the node
            {
                bool ans = dfscycle(i.first, visited);
                if (ans == true)
                {
                    return true;
                }
            }
        }
        return false;
    }

    // --- for directed graph
  
    bool detectcycle()
    {
        unordered_map<T, bool> visited;
        unordered_map<T, bool> dfsvisited;

        for (auto i : adj)
        {
            if (!visited[i.first])
            {
                bool ans = directed_cycle(i.first, visited, dfsvisited);
                if (ans)
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
    g.print();
    if (d == 0) // for undirected graph
    {

        if (g.iscyclic_dfs())
        {
            cout << "yes its a cyclic graph" << endl;
        }
        else
        {
            cout << "no its not a cyclic graph" << endl;
        }
    }
    else{
        if(g.detectcycle())
        {
            cout << "yes its a cyclic graph" << endl;
        }
        else{
            cout << "no its not a cyclic graph" << endl;
        }
    }




    return 0;
}