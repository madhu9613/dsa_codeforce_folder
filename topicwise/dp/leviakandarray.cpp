#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define max3(a, b, c) max(max(a, b), c)
#define max4(a, b, c, d) max(max(a, b), max(c, d))
#define pii pair<int,int>
#define all(x) (x).begin(), (x).end()
#define endl '\n'
#define int ll
ll gcd(ll a, ll b)
{
 return b == 0 ? a : gcd(b, a % b);
}
const int MOD = 1e9 + 7;
const int INF = INT_MAX;

const int MAXN=2006,maxi=2e9+20;
int n,k,a[MAXN];
int dp[MAXN];
bool check(int x)
{
    fill(dp,dp+n,0);
    int ans=0;
    for(int i=0;i<n;i++)
    {
        dp[i]=1;
        for(int j=0;j<i;j++)
        {
            if(abs(a[i]-a[j])<=x*(i-j))
            {
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
        ans=max(ans,dp[i]);
    }
return (n-ans<=k);
}

bool check2(int x)
{
    
}
void solve() {
cin>>n>>k;
for(int i=0;i<n;i++) cin>>a[i];
int low=0,high=maxi;
int ans=0;
while (low<=high)
{
    int mid=low+(high-low)/2;
     if(check(mid))
     {
        ans=mid;
        high=mid-1;
        
     }else{
        low=mid+1;
     }

}

cout<<ans<<endl;

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
   
    while (t--) solve();
    return 0;
}