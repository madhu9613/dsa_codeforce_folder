// Author: Madhujya Rajkhowa
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define all(x) (x).begin(), (x).end()
#define endl '\n'

const int MOD = 1e9 + 7;
const int INF = INT_MAX;
int n,m;
string s;
vector<int>indegree;
vector<vector<int_least64_t>>adj;
vector<int>topoorder;
void solve() {
    cin>>n>>m;cin>>s; 
    adj.resize(n+1);
    indegree.resize(n+1);
    for(int i=0;i<m;i++)
    {
        int a,b;cin>>a>>b;
        adj[a].pb(b);
        indegree[b]++;
    }
    topoorder.clear();
    queue<int>q;
    for(int i=1;i<=n;i++)
    {
        if(indegree[i]==0)
        { 
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int node=q.front();q.pop();
        topoorder.pb(node);
        for(auto &v:adj[node])
        {
            if(--indegree[v]==0)
           {
            q.push(v);
           }
        }
    } 
    
    if(topoorder.size()!=n)
    {
        cout<<-1<<endl;
        return;
    }
    int ans=0;
    //now use dp on dag;
    //dp[u][c]=maximum time c appear when a path ending at 'u';c-(0,25);
    vector<vector<int>>dp(n+1,vector<int>(26,0));
    for(auto &u:topoorder)
    {
        char ch=s[u-1]-'a';
        dp[u][ch]++;
        ans=max(ans,dp[u][ch]);
        for(auto &v:adj[u])
        {
            for(int i=0;i<26;i++)
            {
                dp[v][i]=max(dp[u][i],dp[v][i]);
            }
        }
        
    } 

    cout<<ans<<endl;


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    while (t--) solve();
    return 0;
}

//what i have found is if their is cycle in the graph i move in this caycle and produce a large so -1 and toposort+DAG dp