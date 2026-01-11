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
    int n,m;cin>>n>>m;
    vi x(n);
    queue<int>q;
    map<int,int>dist;
    for(int i=0;i<n;i++)
    {
        cin>>x[i];
        q.push(x[i]);
        dist[x[i]]=0;
    }
    ll ans=0;
    vector<int>res;
    while (!q.empty())
    {
        int cur=q.front();q.pop();
        if(res.size()==m) break;
        if(dist[cur]!=0)
        {
            ans+=dist[cur];
            res.push_back(cur);
        }
        if(!dist.count(cur-1))
        {
            dist[cur-1]=dist[cur]+1;
            q.push(cur-1);
        }
        if(!dist.count(cur+1))
        {
            dist[cur+1]=dist[cur]+1;
            q.push(cur+1);
        }
    }
    cout<<ans<<endl;
    for(int i=0;i<m;i++)
    {
        cout<<res[i]<<" ";
    }
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    
    while (t--)
        solve();

    return 0;
}