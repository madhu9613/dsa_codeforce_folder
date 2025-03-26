#include<bits/stdc++.h>
using namespace std;
int solve(int n, int x,int y,int z)
{
    if(n==0)
    {
        return 0; //zero segment is needed;
    }
    if(n<0)
    {
        return INT_MIN;
    }

    int op1=solve(n-x,x,y,z)+1; //consider x as a answer
    int op2=solve(n-y,x,y,z)+1;
    int op3=solve(n-z,x,y,z)+1;

     return max(op1,max(op2,op3));
}

int solvememo(int n, int x,int y,int z,vector<int> &dp)
{
    if(n==0)
    {
        return 0; //zero segment is needed;
    }
    if(n<0)
    {
        return INT_MIN;
    }
    if(dp[n]!=-1)
    {
        return dp[n];
    }

    int op1=solvememo(n-x,x,y,z,dp)+1; //consider x as a answer
    int op2=solvememo(n-y,x,y,z,dp)+1;
    int op3=solvememo(n-z,x,y,z,dp)+1;

     dp[n]= max(op1,max(op2,op3));
   return dp[n];
}
int solvetab(int target,int x, int y, int z)
{
    vector<int> dp(target+1,-1);
    dp[0]=0;
    
}
int main()
{
    int target;
    cin>>target;
    int x,y,z;
    cin>>x>>y>>z;

    // int ans=solve(target,x,y,z);
    vector<int> dp(target+1,-1);
    int ans=solvememo(target,x,y,z,dp);

  if(ans<0)
{
    cout<<-1; //impossible;
}else{
    cout<<ans;
}
return 0;
}