#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define endl '\n'

const int MOD = 1e9 + 7;
const int INF = INT_MAX;

void solve()
{
   

    int n;
    cin >> n;
    unordered_map<int, int> freq;
    int maxi = 0;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        freq[a]++;
        maxi = max(maxi, a);
    }

    vector<ll> dp(maxi + 1, 0);
    dp[0] = 0;
    dp[1] = 1LL * freq[1] * 1;

    for (int i = 2; i <= maxi; i++)
    {
        dp[i] = max(dp[i - 1], dp[i - 2] + 1LL * i * freq[i]);
    }

    cout << dp[maxi] << endl;
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
