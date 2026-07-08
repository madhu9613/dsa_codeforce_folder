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
    int n;cin>>n;
    vi e(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>e[i];
    }
    vi dp(n+1,INF);
    vi L(n+1),R(n+1);
    for(int i=1;i<=n;i++)
    {
        if(e[i]==0) continue;
        L[i]=max(1,i-e[i]+1);
        R[i]=max(n,i+e[i]-1);

    }
   
    for(int i=1;i<=n;i++)
    {
        if(e[i]==0) continue;
        if(L[i]==1)
        {
            dp[i]=1;
        }
        for(int j=1;j<i;j++)
        {
            if(e[j]==0) continue;
            if(dp[j]==INF) continue;
            // Case 1
            if (R[j] < i && L[i] <= R[j] + 1)
            {
                dp[i] = min(dp[i], dp[j] + 1);
            }

            // Case 2
            if (j < L[i] && R[j] >= L[i] - 1)
            {
                dp[i] = min(dp[i], dp[j] + 1);
            }
        }
    }

    int ans=INF;
    for(int i=1;i<=n;i++)
    {
        if(e[i]==0) continue;
        if(R[i]>=n) ans=min(ans,dp[i]);
    }
    if(ans==INF)
    {
        cout<<-1<<endl;
    }else{
        cout<<ans<<endl;
    }
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