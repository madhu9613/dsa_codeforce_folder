/*Ninja is willing to take some time off from his training and planning a year-long tour. You are given a DAYS array consisting of ‘N’ days when Ninjas will be traveling during the year. Each Day is an integer between 1 to 365 (both inclusive). Train tickets are sold in three different ways:
A 1-day pass is sold for 'COST'[0] coins,
A 7-day pass is sold for 'COST'[1] coins, and
A 30-day  pass is sold for 'COST'[2] coins.
The passes allow for many days of consecutive travel.
Your task is to help the Ninja to find the minimum number of coins required to complete his tour. For example,
If Ninja gets a 7-day pass on day 2, then he can travel for 7 days: 2, 3, 4, 5, 6, 7, and 8.*/
#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &days, vector<int> &cost, int index)
{
    if (index >= days.size())
    {
        return 0;
    }

    // Option 1: 1-day pass
    int op1 = cost[0] + solve(days, cost, index + 1);

    // Option 2: 7-day pass
    int i = index;
    while (i < days.size() && days[i] < days[index] + 7)
    {
        i++;
    }
    int op2 = cost[1] + solve(days, cost, i);

    int j = index;
    while (j < days.size() && days[j] < days[index] + 30)
    {
        j++;
    }
    int op3 = cost[2] + solve(days, cost, j);

    return min(op1, min(op2, op3));
}

// -----using memorization 

int solvememo(vector<int> &days, vector<int> &cost, int index, vector<int> &dp)
{
    if (index >= days.size())
    {
        return 0;
    }
    if (dp[index] != -1)
    {
        return dp[index];
    }
    int op1 = cost[0] + solve(days, cost, index + 1);

    int i = index;
    while (i < days.size() && days[i] < days[index] + 7)
    {
        i++;
    }
    int op2 = cost[1] + solve(days, cost, i);

    int j = index;
    while (j < days.size() && days[j] < days[index] + 30)
    {
        j++;
    }
    int op3 = cost[2] + solve(days, cost, j);

    dp[index] = min(op1, min(op2, op3));
    return dp[index];
}

// ---------using tabulization 
int solvetab(vector<int>&days, vector<int>&cost)
{
    int n=days.size();
    vector<int> dp(n+1,INT_MAX);
    dp[n]=0;
    for(int k=n-1;k>=0;k--)
    {
      
        int op1 = cost[0] + dp[k+1];

       int i = k;
       while (i < days.size() && days[i] < days[k] + 7)
    {
        i++;
    }
    int op2 = cost[1] + dp[i];

    int j = k;
    while (j < days.size() && days[j] < days[k] + 30)
    {
        j++;
    }
    int op3 = cost[2] +dp[j];

    dp[k] = min(op1, min(op2, op3));
     

    }
    return dp[0];

}

int main()
{
    int n;
    cin >> n;
    vector<int> days(n);
    for (int i = 0; i < n; i++)
    {
        cin >> days[i];
    }

    vector<int> cost(3);
    for (int i = 0; i < 3; i++)
    {
        cin >> cost[i];
    }
    vector<int> dp(n + 1, -1);
    // int ans = solve(days, cost, 0);
    int ans = solvememo(days, cost, 0, dp);
    cout << ans;

    return 0;
}
