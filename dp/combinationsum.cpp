#include <bits/stdc++.h>
using namespace std;

void solve(vector<int>& nums, int target, vector<int>& result, vector<vector<int>>& ans) {
    // Base case: if the target is zero, we have found a valid combination
    if (target == 0) {
        ans.push_back(result);
        return;
    }

    // If the target becomes negative, stop processing
    if (target < 0) {
        return;
    }

    for (int i = 0; i < nums.size(); i++) {
        // Choose the current number
        result.push_back(nums[i]);

        // Recur with the reduced target
        solve(nums, target - nums[i], result, ans);

        // Backtrack and undo the choice
        result.pop_back();
    }
}
void solvememo(vector<int>& nums, int target, vector<int>& result, vector<vector<int>>& ans,vector<int> &dp) {

    if (target == 0) {
        ans.push_back(result);
        return;
    }

    // If the target becomes negative, stop processing
    if (target < 0) {
        return;
    }

    for (int i = 0; i < nums.size(); i++) {
        // Choose the current number
        result.push_back(nums[i]);

        // Recur with the reduced target
        solve(nums, target - nums[i], result, ans);

        // Backtrack and undo the choice
        result.pop_back();
    }
}
// ---- only count 
int solvememo(vector<int> nums,int target,vector<int> &dp)
{
    if(target==0)
    {
        return 1;
    }
    if(target<0){
        return 0;
    }
    if(dp[target]!=-1)


    {
        return dp[target];
    }
    int ans=0;
    for(int i=0;i<nums.size();i++)
    {
     ans+=solvememo(nums,target-nums[i],dp);

    }
    dp[target]=ans;
    return dp[target];
}
int main() {
    int n, target;
    cin >> n >> target;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<int> result;              // Temporary vector to store current combination
    // vector<vector<int>> ans;         // Stores all valid combinations
     vector<int> dp(target+1,-1);
    // solve(nums, target, result, ans);

    // // Print the results
    // cout << "Number of combinations: " << ans.size() << endl;
    // for (auto& combination : ans) {
    //     for (int num : combination) {
    //         cout << num << " ";
    //     }
    //     cout << endl;
    // }

int ans=solvememo(nums,target,dp);
cout<<ans;
    return 0;
}
