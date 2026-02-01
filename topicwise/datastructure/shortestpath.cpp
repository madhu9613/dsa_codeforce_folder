/***
 *  simple condition given me k tuple (a,b,c)
 * i am not allowed to move in this ordered in a row;
 * a->b->c;
 * 
 * so its like bfs or finding shortest path in state based;
 * graph;
 * so hashing work ..
 * state  based;
 * 
 */

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define max3(a, b, c) max(max(a, b), c)
#define max4(a, b, c, d) max(max(a, b), max(c, d))
#define pii pair<int, int>
#define pll pair<ll, ll>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl '\n'

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}
ll pow(ll a,ll b,ll m)
{
if(b==0)
 return 1;
if(b==1) return a%m;
 ll temp=pow(a,b/2,m);
 if(b%2==0)
 {
 return (temp*temp)%m;
}
else
{
return (a*(temp*temp)%m)%m ;
}
}

const int MOD = 1e9 + 7;
const int INF = INT_MAX;
const ll LINF = 1e18;

const int MAXN = 40005;
ll encode(int a, int b, int c)
{
    return 1LL * a * 5007 * 5007 + 1LL * b * 5007 + c;
}

void solve() {
    int n,m,k;cin>>n>>m>>k;
    vector<vector<int>>adj(n+1);
    unordered_set<ll>bad;
    bad.reserve(2*k);
    for(int i=0;i<m;i++)
    {
        int a,b;cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=0;i<k;i++)
    {
        int a,b,c;cin>>a>>b>>c;
        bad.insert(encode(a,b,c));
    }
    unordered_map<ll,int>dist;
    unordered_map<ll,ll>par;
    queue<pair<int,int>>q;
    ll start=encode(0,1,0);
    dist[start]=0;
    q.push({0,1});
    ll finish=-1;
    while(!q.empty())
{
    auto [prev,u]=q.front();q.pop();
    ll cs=encode(prev,u,0);
    if(u==n)
    {
        finish=cs;
        break;
    }

    for(int v:adj[u])
    {
        if(bad.count(encode(prev,u,v))) continue;

        ll ns=encode(u,v,0);
        if(!dist.count(ns))
        {
            dist[ns]=dist[cs]+1;
            par[ns]=cs;
            q.push({u,v});
        }
    }
}

if(finish==-1)
{
    cout<<-1<<endl;
    return ;
}

vi path;
ll cur=finish;
while(true)
{
    int city=(cur/5007)%5007;
    path.push_back(city);
    if(!par.count(cur)) break;
    cur=par[cur];
}
reverse(all(path));
cout<<path.size()-1<<endl;
for(int x:path)
{
    cout<<x<<" ";
}cout<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    while (t--)
        solve();

    return 0;
}