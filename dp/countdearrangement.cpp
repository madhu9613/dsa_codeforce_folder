/*here we will find,
consider for set of numbers  
{0,1,2,3....}
let consider for 0 it has (n-1) place so it become 
d(n)=(n-1){ answer of the subproblem}
what is answer of subproblem ...
case1) 0 is at ith place and i is in 0th place means swap*(i,0) means remaining (n-2) elements dearrangement (n-2) place measms d(n-2)
 case2) i should not be in place of 0 so n-1 elemennts dearranegement so d(n-1)
 so 

 d(n)=  ( n - 1 )*( d(n-1) +d(n-2) )

 */

#include<bits/stdc++.h>
using namespace std;
int dearrangement(int n)
{
    if(n==1)
    {
        return 0;
    }
    if(n==2)
    {
        return 1;
    }
    
    return (n-1)*(dearrangement(n-1) +dearrangement(n-2) );
}

int solvememo(int n,vector<int> &dp)
{
    if(n==1)
    {
        return 0;
    }
    if(n==2)
    {
        return 1;
    }
    if(dp[n]!=-1)
    {
        return dp[n];
    }
    dp[n]=(n-1)*(solvememo(n-1,dp)+solvememo(n-2,dp));
    return dp[n];
}
int main()
{
    int n; //set numbers:
    cin>>n;

    // int ans=dearrangement(n);
    vector<int> dp(n+1,-1);
    int ans=solvememo(n,dp);
    cout<<ans<<endl;
    return 0;

}