/*

first master recursion.... at this point i will not say that i am damn good in recursion but not bad also so i am starting 
these from today ......

-----------------------------------------------------
|"THOSE FORGET THE PAST,ARE CONDEMED TO REPEAT IT  " |
-----------------------------------------------------

1) top down process ---->>> recursion+ memorization

2) tabulization____> space optimization

*/
/*
   fibbonaacci series ---->>>>
   
   0 1 1 2 3 5 8 ----

   f(n)=f(n-1) + f(n-2);
   here let say we need to calculate f(6)
   for it we calculate f(5) and f(4)
   for f(5) we need f(4) and f(3) calculate f(4) once and return it to up donot need to calculate more than 1 times
   save it....

------------------------------------------------------------------------------------------
for purly recursive t(c)->2^n with top down memo approach it converted to t(c)->O(n)     |
------------------------------------------------------------------------------------------
*/
#include <iostream>
#include <vector>
using namespace std;

// Step 1: Function with Memoization (Top-Down DP)
int fib(int n, vector<int> &dp)
{
    // Base case
    if (n == 0 || n == 1)
    {
        return n;
    }

    // Step 2: If already calculated, return the cached value
    if (dp[n] != -1)
    {
        return dp[n];
    }

    // Step 3: Calculate and store the result in dp
    dp[n] = fib(n - 1, dp) + fib(n - 2, dp);
    return dp[n];
}
 int bottomupfib(int n)
 {

   vector<int> dp(n+1);
   dp[0]=0;
   dp[1]=1;
   for(int i=2;i<=n;i++)
   {
dp[i]=dp[i-1]+dp[i-2];

   }
   return dp[n];


 }
int main()
{
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    // Check for non-negative input
    if (n < 0)
    {
        cout << "Fibonacci is undefined for negative numbers." << endl;
        return 0;
    }

    // Step 4: Initialize dp vector with -1
    vector<int> dp(n + 1, -1);

    // Call the Fibonacci function
    // int ans = fib(n, dp);
    int ans=bottomupfib(n);

    // Print the result
    cout << "The " << n << "th Fibonacci number is: " << ans << endl;

    return 0;
}
