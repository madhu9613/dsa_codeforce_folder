#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define max3(a, b, c) max(max(a, b), c)
#define max4(a, b, c, d) max(max(a, b), max(c, d))
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()
#define endl '\n'

ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}
const int MOD = 1e9 + 7;
const int INF = INT_MAX;
int n;
vector<vector<int>> adj;
vector<bool> visited;

vector<pii> red;
vi reps;
void dfs(int u, int p = -1)
{
    visited[u] = true;
    for (int v : adj[u])
    {
        if (v == p)
        {
            continue;
        }
        if (visited[v])
        {
            red.pb({u,v});
        }
        else{
            dfs(v,u);
        }
    }
}
void solve()
{
    cin>>n;
    adj.resize(n+1);
    visited.resize(n+1,false);
    for(int i=1;i<n;i++)
    {
        int a,b;cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    for(int i=1;i<=n;i++)
    {
        if(!visited[i])
        {
            dfs(i);
            reps.pb(i);
        }
    }
    cout<<reps.size()-1<<endl;
    for(int i=0;i<reps.size()-1;i++)
    {
        cout<<red[i].first<<" "<<red[i].second<<" "<<reps[i]<<" "<<reps[i+1]<<endl;

    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    while (t--)
        solve();
    return 0;
}