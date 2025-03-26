/***longest inc subsequence  */
#include <bits/stdc++.h>
using namespace std;
int longestincsubsequence(vector<int> nums, int curr, int prev)
{
    if (curr >= nums.size())
    {
        return 0;
    }
    int include = 0;
    if (prev == -1 || nums[curr] > nums[prev])
    {
        include = 1 + longestincsubsequence(nums, curr + 1, curr);
    }
    int exclude = longestincsubsequence(nums, curr + 1, prev);

    return max(include, exclude);
}
int LIS_memo(vector<int> nums, int curr, int prev, vector<vector<int>> &dp)
{

    if (curr >= nums.size())
    {
        return 0;
    }
    int include = 0;
    if (dp[curr][prev + 1] != -1)
    {
        return dp[curr][prev + 1];
    }
    if (prev == -1 || nums[curr] > nums[prev])
    {
        include = 1 + LIS_memo(nums, curr + 1, curr, dp);
    }

    int exclude = LIS_memo(nums, curr + 1, prev, dp);

    dp[curr][prev + 1] = max(include, exclude);

    return dp[curr][prev + 1];
}

int solvetab(vector<int> nums)
{
    int n = nums.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    for (int curr = n - 1; curr >= 0; curr--)
    {
        for (int prev = curr - 1; prev >= -1; prev--)
        {
            int include=0;
            if (prev == -1 || nums[curr] > nums[prev])
            {
                include = 1 + dp[curr][curr+1];
            }

            int exclude = dp[curr][prev+1];
           

            dp[curr][prev + 1] = max(include, exclude);
        }
    }
    return dp[0][0] ;
}

// ------------it doesnot nessesary that the ans vector store the actual subsequence 
int optimise_nlogn(vector<int> nums)
{
    int n=nums.size();
    if(n==0)
    {
        return 0;
    }
    vector<int> ans;
    ans.push_back(nums[0]);
    for(int i=1;i<n;i++)
    {
        if(nums[i]>ans.back())
        {
            ans.push_back(nums[i]);
        }
        else{
            int index=lower_bound(ans.begin(),ans.end(),nums[i])-ans.begin();
            ans[index]=nums[i];
        }
    }
    return ans.size();

}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    // vector<vector<int>> dp(n, vector<int>(n + 1, -1));

    // int ans = LIS_memo(nums, 0, -1, dp);
    // int ans=solvetab(nums);
    int ans=optimise_nlogn(nums);
    cout << ans;

    return 0;
}