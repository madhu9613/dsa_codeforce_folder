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
    vi a(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int B=sqrt(n);
    int dp[B+1][n+2];

    for(int k=1;k<=B;k++)
    {
        for(int i=n;i>=1;i--)
        {
            int nxt=i+a[i]+k;
            if(nxt>n)
            {
                dp[k][i]=1;
            }else{
                dp[k][i]=1+dp[k][nxt];
            }
        }
    }
    int q;cin>>q;
    while(q--)
   {
    int p,k;cin>>p>>k;
    if(k<=B)
    {
        cout<<dp[k][p]<<endl;
    }else{
        int cnt=0;
        while(p<=n)
        {
            p+=a[p]+k;
            cnt++;
        }
        cout<<cnt<<endl;
    }
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