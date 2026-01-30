#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define all(x) (x).begin(), (x).end()
#define endl '\n'

const ll NEG = -1e18;

void solve()
{
    int n, k;
    cin >> n >> k;

    vi a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    vi pos(k + 1, 0);
    int j = 1;
    for (int x = 1; x <= k; x++)
    {
        while (j <= n && a[j] < x)
            j++;
        if (j <= n)
            pos[x] = j;
    }

    vector<vector<ll>> dp(k + 1, vector<ll>(k + 1, NEG));
    dp[0][0] = 0;

    for (int used = 1; used <= k; used++)
    {
        for (int cur = 1; cur <= used; cur++)
        {
            if (!pos[cur])
                continue; 

            for (int prev = 0; prev <= used - cur; prev++)
            {
                if (dp[used - cur][prev] == NEG)
                    continue;

                ll add = 1LL * (cur - prev) * (n - pos[cur] + 1);
                dp[used][cur] = max(
                    dp[used][cur],
                    dp[used - cur][prev] + add);
            }
        }
    }

    ll ans = 0;
    for (int i = 0; i <= k; i++)
        for (int j = 0; j <= k; j++)
            ans = max(ans, dp[i][j]);

    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
