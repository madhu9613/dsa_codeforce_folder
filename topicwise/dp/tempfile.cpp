// #include <bits/stdc++.h>
// using namespace std;

// const long long MOD = 1e9 + 7;

// int main()
// {
//     long long n, k;
//     cin >> n >> k;

//     if (k == 1)
//     {
//         cout << 0 << endl; // no character allowed at all
//         return 0;
//     }

//     vector<long long> dp(k, 0);
//     // dp[j] = number of strings ending with j consecutive same letters
//     // j ranges from 1 to k-1

//     dp[1] = 26; // base case
//     long long total = 26;

//     for (int i = 2; i <= n; i++)
//     {
//         vector<long long> new_dp(k, 0);

//         // case 1: different character
//         new_dp[1] = (total * 25) % MOD;

//         // case 2: same character
//         for (int j = 2; j < k; j++)
//         {
//             new_dp[j] = dp[j - 1];
//         }

//         dp = new_dp;

//         total = 0;
//         for (int j = 1; j < k; j++)
//         {
//             total = (total + dp[j]) % MOD;
//         }
//     }

//     cout << total % MOD << endl;
// }

// #include <bits/stdc++.h>
// using namespace std;

// const long long MOD = 1e9 + 7;

// int main()
// {
//     int n, k;
//     cin >> n >> k;

//     if (k == 1)
//     {
//         cout << 0;
//         return 0;
//     }

//     vector<long long> dp(n + 1), pref(n + 1);

//     dp[0] = 1;
//     pref[0] = 1;

//     for (int i = 1; i <= n; i++)
//     {
//         if (i < k)
//         {
//             dp[i] = (dp[i - 1] * 26) % MOD;
//         }
//         else
//         {
//             long long sum = (pref[i - 1] - pref[i - k] + MOD) % MOD;
//             dp[i] = (25 * sum) % MOD;
//         }
//         pref[i] = (pref[i - 1] + dp[i]) % MOD;
//     }

//     cout << dp[n];
// }

#include <iostream>
#include <vector>

using namespace std;

long long power(long long base, long long exp)
{
    long long res = 1;
    long long MOD = 1e9 + 7;
    base %= MOD;
    while (exp > 0)
    {
        if (exp % 2 == 1)
            res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

int main()
{
    int n, k;
    if (!(cin >> n >> k))
        return 0;

    long long MOD = 1e9 + 7;

    if (k == 0 || k == 1)
    {
        cout << 0 << endl;
        return 0;
    }

    vector<long long> dp(n + 1);
    dp[0] = 1;

    for (int i = 1; i <= n; ++i)
    {
        if (i < k)
        {
            // All combinations are safe
            dp[i] = (dp[i - 1] * 26) % MOD;
        }
        else if (i == k)
        {
            // Subtract the 26 cases where all k characters are identical
            dp[i] = (dp[i - 1] * 26 - 26 + MOD) % MOD;
        }
        else
        {
            // General recurrence
            long long total = (dp[i - 1] * 26) % MOD;
            long long invalid = (dp[i - k] * 25) % MOD;
            dp[i] = (total - invalid + MOD) % MOD;
        }
    }

    cout << dp[n] << endl;

    return 0;
}