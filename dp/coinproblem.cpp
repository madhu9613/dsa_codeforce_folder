#include <bits/stdc++.h>
using namespace std;

int solvememo(vector<int> &nums, int target, vector<int> &dp)
{
    if (target == 0)
    {
        return 0; // Base case: 0 coins needed for target 0.
    }
    if (target < 0)
    {
        return INT_MAX; // Base case: Impossible to make negative target.
    }

    // Check if the result is already computed.
    if (dp[target] != -1)
    {
        return dp[target];
    }

    int mini = INT_MAX;

    // Try each coin recursively.
    for (int i = 0; i < nums.size(); i++)
    {
        int ans = solvememo(nums, target - nums[i], dp);
        if (ans != INT_MAX)
        {
            mini = min(mini, 1 + ans);
        }
    }

    // Store the result in dp array and return.
    dp[target] = mini;
    return mini;
}

int solvetab(vector<int> &nums, int x)
{
   
 vector<int> dp(x+1,INT_MAX);
 dp[0]=0;
 for(int i=0;i<=x;i++)
 {

    for(int j=0;j<nums.size();j++)
    {
        if((i-nums[j])>=0 && dp[i-nums[j]]!=INT_MAX)
        {
        dp[i]=min(dp[i],1+dp[i-nums[j]]);
        }

    }
 }

if(dp[x]==INT_MAX)
{
    return -1;
}
 return dp[x];
}


int main()
{
    int n, x;
    cin >> n >> x; // Input number of coins and target value.
    vector<int> coins(n);
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }

    // Initialize dp array with -1 (uncomputed).
    vector<int> dp(x + 1, -1);

    int result = solvememo(coins, x, dp);
    if (result == INT_MAX)
    {
        cout << -1 << endl; // If no solution, print -1.
    }
    else
    {
        cout << result << endl; // Minimum number of coins.
    }

  
    return 0;

}
