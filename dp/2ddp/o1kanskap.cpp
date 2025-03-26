#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &weight, vector<int> &value, int index, int maxweight)
{
    if (index == 0)
    {
        if (weight[0] <= maxweight)
        {
            return value[0];
        }
        else
        {
            return 0;
        }
    }

    int include = 0;
    if (weight[index] <= maxweight)
    {
        include = value[index] + solve(weight, value, index - 1, maxweight - weight[index]);
    }

    int exclude = solve(weight, value, index - 1, maxweight);

    return max(include, exclude);
}

int solvememo(vector<int> &weight, vector<int> &value, int index, int maxweight, vector<vector<int>> &memo)
{
    if (index == 0)
    {
        if (weight[0] <= maxweight)
        {
            return value[0];
        }
        else
        {
            return 0;
        }
    }

    if (memo[index][maxweight] != -1)
    {
        return memo[index][maxweight];
    }
    int include = 0;

    if (weight[index] <= maxweight)
    {
        include = value[index] + solve(weight, value, index - 1, maxweight - weight[index]);
    }

    int exclude = solve(weight, value, index - 1, maxweight);

    memo[index][maxweight] = max(include, exclude);
    return memo[index][maxweight];
}



int solvetab(vector<int> &weight, vector<int> &value, int n, int maxweight)
{
    vector<vector<int>> dp(n, vector<int>(maxweight + 1, 0));

    for (int w = 0; w <= maxweight; w++)
    {
        if (weight[0] <= w)
        {
            dp[0][w] = value[0];
        }
    }

    for (int index = 1; index < n; index++)
    {
        for (int w = 0; w <= maxweight; w++)
        {
            int include = 0;
            if (weight[index] <= w)
            {
                include = value[index] + dp[index - 1][w - weight[index]];
            }
            int exclude = dp[index - 1][w];
            dp[index][w] = max(include, exclude);
        }
    }
    return dp[n - 1][maxweight];
}
int main()
{
    int n;
    cin >> n;

    if (n == 0)
    { 

        cout << 0;
        return 0;
    }

    vector<int> weight(n);
    vector<int> value(n);

    for (int i = 0; i < n; i++)
    {
        cin >> weight[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> value[i];
    }

    int w;
    cin >> w;

    // int ans = solve(weight, value, n - 1, w); //
    vector<vector<int>> memo(n, vector<int>(w + 1, -1));
    int ans = solvetab(weight, value, n - 1, w);

    cout << ans;

    return 0;
}
