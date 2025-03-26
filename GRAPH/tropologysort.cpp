/*
tropology sort is only applicable for directed a cycalic graph *DAG*
lets know what it is and why..
it is linear ordering of verticsn for every edeg u-v u alwas appear before v in that ordering

*/
#include <bits/stdc++.h>
using namespace std;
template <typename T>
class graph
{
  void topohelp(T  node, unordered_map<T,bool> &visited,stack<T> &s)
  {
    visited[node]=true;
    for(auto neighbour: adj[node])
    { 
        if(!visited[neighbour])
        {
            topohelp(neighbour,visited,s);
        }

    }
    //at last push the node in the stack...
    s.push(node);

  }

public:
    unordered_map<T, vector<T>> adj;
    void insert(T u, T v, T d)
    {
        adj[u].push_back(v);
        if (!d)
        {
            adj[v].push_back(u);
        }
    }
    void print()
    {

         for(auto i:adj)
         {
            cout<<i.first<<"-->";
            for(auto j:i.second)
            {
                cout<<j<<" ";
            }
            cout<<endl;
         }
    }
    // --- topological sorting 

    vector<T> topologicalsort()
    {
        unordered_map<T, bool> visited;
        stack<T> s;
        vector<T> toposort;

        for (auto i : adj)

        {

            if (!visited[i.first])
            {
                topohelp(i.first, visited, s);
              
            }
        }
    //  ---entering element from stack to the vector 
    
        while(!s.empty())
        {
            toposort.push_back(s.top());
            s.pop();
        }

        return toposort;
    }
};

int main()
{
    graph<int> g;
    int n, m, d;
    cin >> n >> m >> d;
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        g.insert(u,v,d);
    }
 g.print();
 vector<int>ans= g.topologicalsort();
 for(auto i:ans)
 { 
     cout<<i<<" ";
  }


    return 0;
}