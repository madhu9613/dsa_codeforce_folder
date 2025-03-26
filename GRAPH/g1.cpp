#include <bits/stdc++.h>
using namespace std;
class Graph{
public:
     map<int, vector<int>> adj; // from u

    void addedges(int u, int v, bool direction)
    {

        // directed direction=1
        /// not directed directon =0

        adj[u].push_back(v);

        if (!direction)
        {
            adj[v].push_back(u);
        }
    }

    // print
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
};

template <typename T>
class graph{
public:

 map<T, vector<T>> adj; 

    void addedges(T u, T v, bool direction)
    {

        // directed direction=1
        /// not directed directon =0

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

} ;







int main()
{

    int n, m, d;
    cin >> n >> m >> d;
    // Graph g; 
    graph<int> g;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin>>u>>v;
        g.addedges(u, v, d);
    }

    g.printgraph();
    g.adj;
    return 0;
}