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

void solve()
{
    int n;
    cin >> n;
    vector<char> cmd(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> cmd[i];

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    // first statement at level=0;
    dp[1][0] = 1;
    for (int i = 1; i < n; i++)
    {
        if (cmd[i] == 'f')
        {
            // preveous
            for (int j = 1; j <= i; j++)
            {
                dp[i + 1][j] = dp[i][j - 1];
            }
            dp[i + 1][0] = 0;
        }
        else
        {

            int s = 0;
            for (int j = i; j >= 0; j--)
            {
                s = (s + dp[i][j]) % MOD;
                dp[i + 1][j] = s;
            }
        }
    }

    int ans=0;
    for(int j=0;j<=n;j++)

    {
        ans=(ans+dp[n][j])%MOD;
    }
    cout<<ans<<endl;
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