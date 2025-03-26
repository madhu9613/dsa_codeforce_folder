/*There is a 3 lane road of length n that consists of n + 1 points labeled from 0 to n. A frog starts at point 0 in the second lane and wants to jump to point n. However, there could be obstacles along the way.

You are given an array obstacles of length n + 1 where each obstacles[i] (ranging from 0 to 3) describes an obstacle on the lane obstacles[i] at point i. If obstacles[i] == 0, there are no obstacles at point i. There will be at most one obstacle in the 3 lanes at each point.

For example, if obstacles[2] == 1, then there is an obstacle on lane 1 at point 2.
The frog can only travel from point i to point i + 1 on the same lane if there is not an obstacle on the lane at point i + 1. To avoid obstacles, the frog can also perform a side jump to jump to another lane (even if they are not adjacent) at the same point if there is no obstacle on the new lane.*/
#include<bits/stdc++.h>
using namespace std;
int solve(vector<int> obs,int cl, int pos)
{
    int n=obs.size()-1;
    //is pos==n
    if(pos==n)
    {
        return 0;
    }
    int jump=0;
    if(obs[pos+1]!=cl) //if at  next position in the same line no obstracle present we can move forward::
    {
        return solve(obs,cl,pos+1);
    }
    else
    {
        for(int i=1;i<=3;i++) //i have to move jump to different line
        {
            int ans=INT_MAX;
            if(cl!=i && obs[pos]!=i)
            {
               ans=min(ans,1+solve(obs,i,pos));
               return ans; 
            }

        }
    }
 
}

// --- using memo 
int solvememo(vector<int> obs,int cl, int pos,vector<vector<int> > &dp)
{
    int n=obs.size()-1;
    //is pos==n
    if(pos==n)
    {
        return 0;
    }
     if(dp[cl][pos]!=-1)
     {
        return dp[cl][pos];
     }

    if(obs[pos+1]!=cl) //if at  next position in the same line no obstracle present we can move forward::
    {
        return solvememo(obs,cl,pos+1,dp);
    }
    else
    {
        for(int i=1;i<=3;i++) //i have to move jump to different line
        {
            int ans=INT_MAX;
            if(cl!=i && obs[pos]!=i)
            {
               ans=min(ans,1+solvememo(obs,i,pos,dp));
               dp[cl][pos]=ans;
               return dp[cl][pos]; 
            }

        }
    }
 
}
int main()
{
    int n;
    cin>>n;
    vector<int> obs(n+1);
    for(int i=0;i<=n;i++)
    {
        cin>>obs[i];
    }
    vector<vector<int> >dp(4, vector<int> (n+1,-1));
    // int ans=solve(obs,2,0);
    int ans=solvememo(obs,2,0,dp);
    cout<<ans;
    return 0;
}