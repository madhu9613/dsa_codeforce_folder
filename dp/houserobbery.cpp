/**
 * Mr. X is a professional robber planning to rob houses along a street. Each house has a certain amount of money hidden.
All houses along this street are arranged in a circle. That means the first house is the neighbour of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses are broken into on the same night.

You are given an array/list of non-negative integers 'ARR' representing the amount of money of each house. Your task is to return the maximum amount of money Mr. X can rob tonight without alerting the police.
 */
#include <bits/stdc++.h>
using namespace std;
int findmaxnonadj(vector<int> nums, vector<int> dp, int n)
{
    if (n == 0)
    {
        return nums[0];
    }
    if (n < 0)
    {
        return 0;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    int include = findmaxnonadj(nums, dp, n - 2) + nums[n];
    int exclude = findmaxnonadj(nums, dp, n - 1);

    dp[n] = max(include, exclude);
    return dp[n];
}
int main()
{
    int n;
    cin >> n;
    vector<int> first;
    vector<int> second;
    for (int i = 0; i < n; i++)
    {
        int data;
        cin >> data;
        if (i == 0)
        {
            first.push_back(data);
            continue;
        }
        if (i == n - 1)
        {
            second.push_back(data);
            continue;
        }
        first.push_back(data);
        second.push_back(data);
    }

vector<int> dp(n,-1);
int solve1=findmaxnonadj(first,dp,n-2);
int solve2=findmaxnonadj(second,dp,n-2);
int ans=max(solve1,solve2);
cout<<ans<<endl;
    return 0;
}