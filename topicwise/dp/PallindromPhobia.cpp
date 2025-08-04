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

vector<vector<int>> dp;

int mininsertion(string s, int i, int j)
{
    if (i == j)
    {
        return 0;
    }
    if (i > j)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    if (s[i] != s[j])
    {
        int a = mininsertion(s, i + 1, j) + 1;
        int b = mininsertion(s, i, j - 1) + 1;
        dp[i][j] = min(a, b);
    }
    else
    {
        dp[i][j] = mininsertion(s, i + 1, j - 1);
    }
    return dp[i][j];
}
void solve()
{
    string s;
    cin >> s;
    int n=s.length();
    dp.assign(n+1,vector<int>(n+1,-1));
    int ans = mininsertion(s, 0, s.length() - 1);
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}