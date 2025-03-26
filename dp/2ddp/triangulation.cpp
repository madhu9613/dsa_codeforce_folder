/** triangulation of polygon... */
#include<bits/stdc++.h>
using namespace std;
int solve(vector<int> &values,int i,int j,vector<vector<int> > &dp)
{
    if(i+1==j) //only two nodes no scope of making triangle
    {
        return 0;
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
     int ans=INT_MAX;
    for(int k=i+1;k<j;k++)
    {
       ans=min(ans,values[i]*values[j]*values[k]+solve(values,i,k,dp)+solve(values,k,j,dp));

    }

    dp[i][j]=ans;
    return dp[i][j];
}

// ---tabulization 
int solvetab(vector<int> &values)
{
    int n=values.size();
    vector<vector<int> > dp(n,vector<int> (n,INT_MAX));
    for(int i=n-1;i>=0;i--)
    {
        for(int j=i+2;j<=n;j++)
        {

        }
    }
}
int main()
{
    int n;
    cin>>n;
    vector<int> values(n);
    for(int i=0;i<n;i++)
    {
        cin>>values[i];
    }
    vector<vector <int> > dp(n,vector<int> (n,-1));
    int ans=solve(values,0,n-1,dp);
    cout<<ans<<endl;
    return 0;
}