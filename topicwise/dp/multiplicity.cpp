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

ll gcd(ll a, ll b)
{
 return b == 0 ? a : gcd(b, a % b);
}
const int MOD = 1e9 + 7;
const int INF = INT_MAX;

// void solve() {
//     int n;cin>>n;
//     vi a(n+1);
//     for(int i=1;i<=n;i++)
//      {
//         cin>>a[i];
//      }

//      vector<vector<int>>dp(n+1,vector<int>(n+1,0));
//      for(int i=1;i<=n;i++)
//      {
//         dp[i][1]=1;
//         for(int len=2;len<=n;len++)
//         {
//             if(a[i]%len==0)
//             {
//                 ll sumprev=0;
//                 for(int j=1;j<i;j++)
//                 {
//                     sumprev+=dp[j][len-1];
//                     if(sumprev>=MOD) sumprev-=MOD;
//                 }
//                 dp[i][len]=sumprev%MOD;
//             }
//         }
//      }

//      ll ans=0;
//      for(int i=1;i<=n;i++)
//      {
//         for(int len=1;len<=n;len++)
//         {
//             ans=(ans+dp[i][len])%MOD;
//         }
//      }
//      cout<<ans<<endl;

// }


//let dp[len]=number of good subsequence oof length (len) so far'
//len is updated when a[j] is divisibel be len;
//dp[i][len]=dp[i-1][len] //we can skip all len except those taht divide a[j]
//




void solve()
{
    int n;cin>>n;
    vi a(n);
    int maxi=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
         maxi=max(maxi,a[i]);
     }
     vector<vector<int>>divisor(maxi+1);
     for(int d=1;d<=maxi;d++)
     {
        for(int m=d;m<=maxi;m+=d)
        {
            divisor[m].pb(d);
        }
     }
   
     vector<int>dp(n+1,0);
     for(int x:a)
     {
        auto divs=divisor[x];
        sort(all(divs));
        reverse(all(divs));
        for(int len:divs)
        {
            if(len>n) continue;
            if(len==1) dp[1]=(dp[1]+1)%MOD;
            else dp[len]=(dp[len]+dp[len-1])%MOD;
  
        }
     }

     ll ans=0;
     for(int len=1;len<=n;len++)
     {
        ans=(ans+dp[len])%MOD;
     }

     cout<<ans<<endl;



}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
   int  t=1;
    while (t--) solve();
    return 0;
}