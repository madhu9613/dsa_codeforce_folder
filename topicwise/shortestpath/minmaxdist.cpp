//http://codeforces.com/problemset/problem/1881/F

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

void solve() {
    int n,k;cin>>n>>k;
    vector<int>marked(k);
    vector<bool>ismarked(n+1,false);
    for(int i=0;i<k;i++)
    {
        cin>>marked[i];
        ismarked[marked[i]]=true;
    }
    vector<vector<int>>adj(n+1);
    for(int i=0;i<n-1;i++)
    {
        int a,b;cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    auto bfs=[&](int u,vector<int>&dist)->int
    {
        queue<int>q;
        fill(all(dist),INF);
        dist[u]=0;
        int farthest=u;
        q.push(u);
        while(!q.empty())
        {
            int node=q.front(); q.pop();
            if(ismarked[node] && dist[node]>dist[farthest])
            {
                farthest=node;
            }
            for(int v:adj[node])
            {
                if(dist[v]==INF)
                {
                    dist[v]=dist[node]+1;
                    q.push(v);
                }

            }
        }
        return farthest;
    };
    vector<int>dist1(n+1),dist2(n+1);
    int a=bfs(marked[0],dist1);
    int b=bfs(a,dist1);

    bfs(b,dist2);

    int ans=INF;
    for(int i=1;i<=n;i++)
    {

        ans=min(ans,max(dist1[i],dist2[i]));
        
    }
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--)
        solve();

    return 0;
}