// https://codeforces.com/problemset/problem/1307/D
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
    int n,m,k;cin>>n>>m>>k;
    vector<int>s(k);
    for(int i=0;i<k;i++)
    {
        cin>>s[i];
    }
    vector<vector<int>>adj(n+1);
    for(int i=0;i<m;i++)
    {
        int a,b;cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int>dist1(n+1,INF);
    vector<int>dist2(n+1,INF);
    queue<int>q;
    dist1[1]=0;
    q.push(1);

    while(!q.empty())
    {
        int u=q.front(); q.pop();
        for(auto &v:adj[u])
        {
            if(dist1[v]==INF)
            {
                dist1[v]=dist1[u]+1;
                q.push(v);
            }
        }
    }

    dist2[n]=0;
    q.push(n);
    while(!q.empty())
    {
        int u=q.front(); q.pop();
        for(auto &v:adj[u])
        {
            if(dist2[v]==INF)
            {
                dist2[v]=dist2[u]+1;
            }
        }
    }
//     // need to sort the s nodes x-y by;
//     sort(all(s),[](const &a,const &b)
// {

// });


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while (t--)
        solve();

    return 0;
}