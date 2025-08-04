#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()
#define endl '\n'

const int MOD = 1e9 + 7;
const int INF = INT_MAX;

vi v;
int n;
vector<vector<ll>> dp;

ll maxiscore(ll l, ll r, ll a)
{
    if (l > r)
        return 0;
    if (dp[l][r] != -1)
        return dp[l][r];
    return dp[l][r] = max(v[l] * a + maxiscore(l + 1, r, a + 1),
                          v[r] * a + maxiscore(l, r - 1, a + 1));
}

void solve()
{
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    dp.assign(n, vector<ll>(n, 0));
    for (int i = 0; i < n; i++)
    {
        dp[i][i] = v[i] * n;
    }
    for (int len = 2; len <= n; len++)
    {
        for (int l = 0; l + len <= n; l++)
        {
            int r=l+len-1;
            int age=n-(r-l);
           dp[l][r]=max(
            v[l]*age+dp[l+1][r],
            v[r]*age+dp[l][r-1]
           );
        }
    }

    cout<<dp[0][n-1]<<endl;
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
