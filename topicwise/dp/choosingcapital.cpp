//it is the concept of re-rooting
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
vector<vector<pair<int,int>>>adj;
vector<int>dp;
void dfs1(int u,int par=-1)
{
    for(auto &[v,dir]:adj[u])
    {
        if(v==par) continue;
        dp[1]+=dir;
        dfs1(v,u);
    }
}

void dfs2(int u,int par=-1)
{
    for(auto &[v,dir]:adj[u])
    {
        if(v==par) continue;

        dp[v]=dp[u]+(dir==1?-1:1);
        dfs2(v,u);
    }
}
void solve() {
int n;cin>>n;
adj.resize(n+1);
dp.resize(n+1);
for(int i=1;i<n;i++)
{
    int a,b;cin>>a>>b;
    adj[a].push_back({b,0});//we donot need to reverse it ;
    adj[b].push_back({a,1}) ;//to move from b to a i need to reverse it;
}
dfs1(1); dfs2(1);
vector<int>res;

for(int i=1;i<=n;i++)
{
    if(res.empty()||dp[i]<dp[res[0]])
    {
        res.clear();
        res.push_back(i);
    }else if(dp[i]==dp[res[0]])
    {
        res.push_back(i);
    }
}
cout<<dp[res[0]]<<endl;
for(int i:res)
{
    cout<<i<<" ";
}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}