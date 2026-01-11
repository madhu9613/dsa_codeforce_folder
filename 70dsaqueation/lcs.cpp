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

ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}

ll lcm(ll a, ll b)
{
    return a / gcd(a, b) * b;
}

const int MOD = 1e9 + 7;
const int INF = INT_MAX;
const ll LINF = 1e18;

const int MAXN = 40005;

vector<vector<int>> buildLcs(const string &a, const string &b)
{
    int n = a.size();
    int m = b.size();

    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp;
}

ll countlcs(const string &s,const string &b)
{
    int n=a.size();
    int m=b.size();
    vector<vector<int>>dp=buildLcs(a,b);
    for(int i=0;i<n;i++) ways[i][0]=1;
    for(int j=0;k<=m;j++) ways[0][j]=1;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i-1]==b[j-1])
            {
                ways[i][j]=ways[i-1][j-1];
            }else{
                ll val=0;
                if(dp[i-1][j]==dp[i][j])
                {
                    val=(val+ways[i-1][j])%MOD;
                }
                if(dp[i][j-1]==dp[i][j])
                {
                    val=(val+ways[i][j-1])%MOD;
                }
                if(dp[i-1][j-1]==dp[i][j])
                {
                    val=(val-ways[i-1][j-1]+MOD)%MOD;
                }

                ways[i][j]=val;
            }
        }
    }
    return ways[n][m];
}

void solve()
{
    string a, b;
    cin >> a >> b;
    lcs(a, b);
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