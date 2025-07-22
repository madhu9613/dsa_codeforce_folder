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
vector<vector<int>>adj;
vll coin;
vector<bool>visited;
ll ans=0;
ll dfs(int u,int p=-1)
{
    ll mini=coin[u];
    visited[u]=true;
    for(auto &v:adj[u])
    {
       if(!visited[v])
       {
         mini= min(mini,dfs(v,u));
       }
    }
 return mini;  
}

void solve() {
cin>>n>>m;
adj.resize(n+1);
coin.resize(n+1);
for(int i=1;i<=n;i++)
{
    cin>>coin[i];
}
for(int i=0;i<m;i++)
{
    int a,b;cin>>a>>b;
   adj[a].push_back(b);
   adj[b].push_back(a);
}
visited.resize(n+1,false);
for(int i=1;i<=n;i++)
{
    if(!visited[i])
    {
        ans+=dfs(i);
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