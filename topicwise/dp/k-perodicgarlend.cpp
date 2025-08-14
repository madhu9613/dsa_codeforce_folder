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

void solve() {
    int n,k;cin>>n>>k;

    string s;cin>>s;
    s=" "+s;
    vi prefix(n+1,0),dp(n+1,0);

    for(int i=1;i<=n;i++)
    {
     prefix[i]=prefix[i-1];
     if(s[i]=='1') prefix[i]++;
    }


    int ans=prefix[n];
    for(int i=1;i<=n;i++)
    {
        int cost=(s[i]=='1' ?0:1);
        dp[i]=cost+prefix[i-1];
        
        if(i>=k)
        {
            dp[i]=min(dp[i],cost+dp[i-k]+prefix[i-1]-prefix[i-k]);

        }

        ans=min(ans,dp[i]+(prefix[n]-prefix[i]));

    }
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}