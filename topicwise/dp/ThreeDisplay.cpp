// Author: Madhujya Rajkhowa
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define endl '\n'

void solve()
{
    int n;
    cin >> n;
    vll fs(n + 1), cost(n + 1);

    for (int i = 1; i <= n; i++) cin >> fs[i];
    for (int i = 1; i <= n; i++) cin >> cost[i];

    ll ans = LLONG_MAX;

    // Fix j and find min cost on both sides
    for (int j = 2; j <= n - 1; j++)
    {
        ll min_in_left = LLONG_MAX, min_in_right = LLONG_MAX;

        for (int i = 1; i < j; i++)
        {
            if (fs[i] < fs[j])
                min_in_left = min(min_in_left, cost[i]);
        }

        for (int k = j + 1; k <= n; k++) 
        {
            if (fs[j] < fs[k])
                min_in_right = min(min_in_right, cost[k]);
        }

        if (min_in_left != LLONG_MAX && min_in_right != LLONG_MAX)
        {
            ans = min(ans, min_in_left + cost[j] + min_in_right);
        }
    }

    if (ans == LLONG_MAX)
        cout << -1 << endl;
    else
        cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
