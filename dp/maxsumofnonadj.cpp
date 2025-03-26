/*
You are given an array/list of ‘N’ integers. You are supposed to return the maximum sum of the subsequence with the constraint that no two elements are adjacent in the given array/list.
110 2 3 788 90 what is the maximum sum
it can be (110+3+90)
or (110+788+90) also possible

*/
#include<bits/stdc++.h>

using namespace std;
int solve(vector<int> nums, int n) //n is last element;
{
    if(n<0)
{
    return 0;
}
if(n==0) //its the only so include it
{
    return nums[n];
}

int include=solve(nums,n-2)+nums[n]; //including element
int exclude=solve(nums,n-1); //excluding it 


return max(include,exclude);

}
int solvememo(vector<int> nums, int n,vector<int> &dp) //n is last element;
{
    if(n<0)
{
    return 0;
}
if(n==0) //its the only so include it
{
    return nums[n];
}
//if alredy calculatd return it:
if(dp[n]!=-1)
{
    return dp[n];
}

int include=solve(nums,n-2)+nums[n]; //including element
int exclude=solve(nums,n-1); //excluding it 

dp[n]=max(include,exclude);

return dp[n];
}

int solvetabulization(vector<int> nums)
{
    int n=nums.size();
    vector<int>dp(n,-1);
    // --- initialize dp
    dp[0]=nums[0];
    dp[1]=max(nums[0],nums[1]);
    // -- convert recursive dp relation 
    for(int i=2;i<n;i++)
    {
        // include?
        int include=dp[i-2]+nums[i];
        int exclude=dp[i-1];
        dp[i]=max(include,exclude);
    }

return dp[n-1];
}
int main()
{
    int n;
    cin>>n;
    vector<int> nums;
    for(int i=0;i<n;i++)
    {
        int data;
        cin>>data;
        nums.push_back(data);
    }
int N=nums.size();
vector<int> dp(n,-1);
// int ans=solve(nums,nums.size()-1);

// int ans=solvememo(nums,N-1,dp);
int ans=solvetabulization(nums);
cout<<ans<<endl;

    return 0;
}