/*
Given a number n, find the minimum number of perfect squares (square of an integer) that sum up to n. 
for 100 its 1 as 10 square =100
for n=6;
1*1 +1*1+2*2     three numbers are required;;

*/

#include<bits/stdc++.h>
using namespace std;

//  --pure recursion 
int solve(int n)
{
    if(n==0)
    {
        return 0;
    }
    
    int ans=n;
    for(int i=1;i*i<=n;i++)
    {
        int temp=i*i;
        ans=min(ans, 1+solve(n-temp));
    }

    return ans;
}

// --- using memorization 

int solvememo(int n,vector<int> &dp)
{
    if(n==0)
    {
        return 0;
    }
    
    if(dp[n]!=-1)
    {
        return dp[n];
    }
    int ans=n;
    for(int i=1;i*i<=n;i++)
    {
        int temp=i*i;
        ans=min(ans, 1+solvememo(n-temp,dp));
    }
  dp[n]=ans;
  return dp[n];
}
int main()
{
    int n;
    cin>>n;
  vector<int> dp(n+1,-1);
    int ans=solvememo(n,dp);
    cout<<ans;
    return 0;
}