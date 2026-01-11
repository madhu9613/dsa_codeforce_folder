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

// if a particular bits shared with atleast 3 integers then they will definy going
// to form a cycle 
//we only 

void solve() {
    int n;cin>>n;
    vll a;
    for(int i=0;i<n;i++)
    {
        ll x;cin>>x;
        if(x!=0)
        {
            a.push_back(x);
        }
    }
    n=a.size();
    if(n==0)
    {
        cout<<-1<<endl;
        return;
    }
    vector<vector<int>>bit(61);
    for(int i=0;i<n;i++)
    {
        for(int b=0;b<=60;b++)
        {
            if(a[i]&(1LL<<b))
            {
                bit[b].push_back(i);
                if(bit[b].size()>=3)
                {
                    cout<<3<<endl;
                    return;
                }
            }
        }
    }
    // make graph;
vector<set<int>>adj(n);

for(int b=0;b<=60;b++)
{
    if(bit[b].size()==2)
    {
        int u=bit[b][0];
        int v= bit[b][1];
        adj[u].insert(v);
        adj[v].insert(u);
    }
}


int ans=INF;
for(int s=0;s<n;s++)
{
    vi dist(n,INF),par(n,-1);
    queue<int>q;
    dist[s]=0;
    q.push(s);
    while (!q.empty())
    {
        int u=q.front(); q.pop();
        for(int v:adj[u])
        {
            if(dist[v]==INF)
            {
                dist[v]=dist[u]+1;
                par[v]=u;
                q.push(v);
            }else if(par[u]!=v)
            {
                ans=min(ans,dist[u]+dist[v]+1);
            }
        }
    }
}
cout<<(ans==INF?-1:ans)<<endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
  
    while (t--)
        solve();

    return 0;
}