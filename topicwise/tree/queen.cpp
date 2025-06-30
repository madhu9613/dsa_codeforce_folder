#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>children;
vector<int>c;
int main()
{
    int n;
    cin>>n;
    children.resize(n+1);
    c.resize(n+1);
    for(int i=1;i<=n;i++)
    {
        int p;
        cin>>p>>c[i];
        if(p!=-1)
        {
          children[p].push_back(i);
        }
    }
    vector<int> deletable;
    
    for(int i=1;i<=n;i++)
    {
        if(c[i]==1)
        {bool del=true;
            //check for its children
            for(auto &ch:children[i])
            {
                if(c[ch]==0)
                {
                     del=false;
                     break;
                }
            }
            if(del)
            {
                deletable.push_back(i);
            }
        }
    }
    if(deletable.size()==0)

    {
        cout<<-1<<endl;
        return 0;
    }

    for(auto &i:deletable)
    {
        cout<<i<<" ";
    }

    return 0;
}