#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define max3(a, b, c) max(max(a, b), c)
#define max4(a, b, c, d) max(max(a, b), max(c, d))
#define pii pair<int,int>
#define pll pair<ll,ll>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl '\n'

ll gcd(ll a, ll b)
{
 return b == 0 ? a : gcd(b, a % b);
}
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
const int MOD = 1e9 + 7;
const int INF = INT_MAX;
const ll LINF = 1e18;
const int MAXN=2e5+6;
vi g[MAXN];
int tin[MAXN],low[MAXN],sz[MAXN],timer;
bool vis[MAXN];
ll n,m,maxprod;

void dfs(int u,int p=-1)
{
    vis[u]=true;
    tin[u]=low[u]=++timer;
    sz[u]=1;
    for(int v:g[u])
    {
        if(v==p) continue;
        if(vis[v])
        {
          low[u]=min(low[u],tin[v]);
        }else{
       dfs(v,u);
       sz[u]+=sz[v];
       low[u]=min(low[u],low[v]);
       if(low[v]>tin[u])
       {
        ll a=sz[v];
        ll b=n-a;
        maxprod=max(maxprod,a*b);
       }
        }
    }
}

void solve() {
cin>>n>>m;
for(int i=1;i<=n;i++)
{
    g[i].clear();
    vis[i]=false;
    tin[i]=low[i]=0;
    sz[i]=0;
}
timer=0;
maxprod=0;
for(int i=0;i<m;i++)
{
    int x,y;cin>>x>>y;
    g[x].pb(y);
    g[y].pb(x);
}
dfs(1);
ll total=n*(n-1)/2;
cout<<total-maxprod<<endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}