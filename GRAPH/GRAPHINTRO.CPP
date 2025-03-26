/* 
            WELCOME YOU TO GRAPH
         -----   --------------------------
      GRAPH IS A data structure which is combination of node and edges....
       it can be directed and undirected 
       SOME TERM IS  
       degree how many node connected to it and inc case of directed in can be also indegree how many node points
       towads me and outdegree outside simple............



*/
/*adjacency matrix */
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    int m;
    cin>>n>>m; //nodes and edges
    // next it will give m pairs from to where 
    vector<pair<int,int> > edges; //ordered from to where 
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
     pair<int, int> p=make_pair(a,b);
       edges.push_back(p);
    }

       vector<vector<int>> adjMatrix(n, vector<int>(n, 0)); //initialize to zero [{0,0,0},{0,0,0},{0,0,0}]

       for(auto i:edges)
       {
       int from=i.first;
       int to=i.second;
       adjMatrix[from][to]=1;
       }

       //printing the matrix;
       for(int i=0;i<n;i++)
       {
        for(int j=0 ; j<n ;j++)
        {
            cout<<adjMatrix[i][j]<<" ";    
        }
        cout<<endl;
       }


    return 0;
}