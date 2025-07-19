// i need to consume all three vitamine A B C and need to minimize the price also]
// dp[mask]=min number of money requied to consummke all this included vitamine

// Author: Madhujya Rajkhowa
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define all(x) (x).begin(), (x).end()
#define endl '\n'

const int MOD = 1e9 + 7;
const int INF = INT_MAX;

void solve()
{
    int n;
    cin >> n;
    vector<pair<ll, string>> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second;
    }

    vector<ll> dp(8, INF);
    dp[0] = 0;
    for (int i = 0; i < n; i++)
    {
        // create mask;
        int mask = 0;
        for (auto &s : v[i].second)
        {
            if (s == 'A')
                mask |=(1 << 0);
            if (s == 'B')
                mask |= (1 << 1);
            if (s == 'C')
                mask |=(1 << 2);
        }

        for (int j = 0; j < 8; j++)
        {
            if (dp[j] != INF)
            {
                int new_mask = j | mask;
                dp[new_mask] = min(dp[new_mask], dp[j] + v[i].first);
            }
        }
    }
    if (dp[7] == INF)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << dp[7] << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}