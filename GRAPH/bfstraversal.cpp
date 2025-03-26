/*
WELCOME TO
BRETH FIRST SEARCH :BFS
also try to disconnected graph
YOU ARE GIVEN
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
};

vector<int> bfs(int n, graph<int> g)
{

    vector<int> ans;
    unordered_map<int, bool> visited;
    queue<int> q; // for storing of performing the task

//  node starting with 0
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            q.push(i);
            visited[i] = true;

            while (!q.empty())
            {
                int node = q.front();
                q.pop();
                ans.push_back(node);

                for (int neighbour : g.adj[node])
                {
                    if (!visited[neighbour])
                    {
                        q.push(neighbour);
                        visited[neighbour] = true;
                    }
                }
            }
        }
    }
    return ans;

}

int main()
{ 
    graph<int> g;
    int n, m, d;
    cin >> n >> m >> d;
   for(int i=0;i<m;i++)
   {
    int u,v;
    cin>>u>>v;
    g.addedges(u,v,d);
   }
   g.printgraph();   vector<int> bfs_traversal=bfs(n,g);
   for(int i=0;i<n;i++)
   {
    cout<<bfs_traversal[i]<<" ";
   }

    return 0;
}