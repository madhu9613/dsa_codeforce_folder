//https://codeforces.com/problemset/problem/1611/E1

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
    vector<int>color(n+1,-1);
    queue<int>q;
    for(int i=0;i<k;i++)
    {
        int x;cin>>x;
        color[x]=0;
        q.push(x);
    }
    color[1]=1;
    q.push(1);
    vector<vector<int>>adj(n+1);
    for(int i=0;i<n-1;i++)
    {
        int a,b;cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    while (!q.empty())
    {
        int u=q.front(); q.pop();
        if(color[u]==1 && u!=1 &&adj[u].size()==1)
        {
            cout<<"YES"<<endl;
            return;
        }

        for(int v:adj[u])
        {
            if(color[v]==-1)
            {
                color[v]=color[u];
                q.push(v);
            }
        }

    }
    cout<<"No"<<endl;
    
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