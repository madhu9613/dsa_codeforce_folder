#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define max3(a, b, c) max(max(a, b), c)
#define max4(a, b, c, d) max(max(a, b), max(c, d))
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()
#define endl '\n'

ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}
const int MOD = 1e9 + 7;
const int INF = INT_MAX;

// eat red and white flowers'
// for dinner tobe testy he eats white flower in group of size  k;
//  Now Marmot wonders in how many ways he can eat between a and b flowers. As the number of ways could be very large,
//   k=2;

const int MAXN = 1e5 + 5;
void solve()
{
    int q, k;
    cin >> q >> k;
    vector<vector<ll>> dp(MAXN, vector<ll>(2, 0));
    vector<ll> prefix(MAXN,0);
    dp[0][0] = 0; // as he will eat in group of k only
    dp[0][1] = 1;
    for (int i = 1; i <MAXN; i++)
    {
        dp[i][1] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;

        if (i >= k)
        {
            dp[i][0] = (dp[i - k][0] + dp[i - k][1]) % MOD;
        }
        else
        {
            dp[i][0] = 0;
        }
    }

    for(int i=1;i<MAXN;i++)
    {
        ll total=(dp[i][0]+dp[i][1])%MOD;
        prefix[i]=(prefix[i-1]+total)%MOD;
    }
    while (q--)
    {
        int a,b;cin>>a>>b;
        cout<<(prefix[b]-prefix[a-1]+MOD)%MOD<<endl;
    }
    
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;

    while (t--)
        solve();
    return 0;
}