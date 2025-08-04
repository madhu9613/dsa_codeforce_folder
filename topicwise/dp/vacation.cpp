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
    vi a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    // dp[i][0] -> rest
    // dp[i][1] -> contest
    // dp[i][2] -> gym
    vector<vector<int>> dp(n, vector<int>(3, INF));
    dp[0][0] = 1;
    if (a[0] == 1 || a[0] == 3)
        dp[0][1] = 0;
    if (a[0] == 2 || a[0] == 3)
        dp[0][2] = 0;

    for (int i = 1; i < n; i++)
    {
        dp[i][0] = 1 + min({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]});

        if (a[i] == 1 || a[i] == 3)
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]);

        if (a[i] == 2 || a[i] == 3)
            dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]);
    }

    cout << min({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]}) << endl;
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
