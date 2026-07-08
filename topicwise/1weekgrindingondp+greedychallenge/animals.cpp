#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, X;
    cin >> n >> X;

    vector<int> cost(n);
    for (int i = 0; i < n; i++)
    {
        int c;
        cin >> c;
        cost[i] = (n - i) * c;
    }

    vector<int> dp(X + 1, 0);

    for (int i = 0; i < n; i++)
    {
        for (int j = X; j >= cost[i]; j--)
        {
            dp[j] = max(dp[j], dp[j - cost[i]] + 1);
        }
    }

    cout << dp[X] << endl;
    return 0;
}