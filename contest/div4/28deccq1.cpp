#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<long long, long long> memo; // Memoization cache for smaller cases

// Function to calculate lucky value for a segment [l, r] with minimum length k
long long calculateLuckyValue(long long l, long long r, long long k) {
    // If the length of the segment is less than k, return 0 (stop recursion)
    if (r - l + 1 < k) return 0;
    
    // Check if the result for this segment is already computed
    long long key = (l * 1000000000000) + r; // Unique key for each segment
    if (memo.find(key) != memo.end()) {
        return memo[key];
    }
 
    // If the segment length is 1 (base case), directly return the sum
    if (k == 1) {
        return r * (r + 1) / 2; // Direct calculation for sum of numbers 1 to n
    }

    long long m = (l + r) / 2; // Middle star (index)

    long long luckyValue = 0;
    
    if ((r - l + 1) % 2 == 1) {
        // Odd length, add middle star to lucky value
        luckyValue += m;
        // Split into [l, m-1] and [m+1, r]
        luckyValue += calculateLuckyValue(l, m - 1, k);
        luckyValue += calculateLuckyValue(m + 1, r, k);
    } else {
        // Even length, split into [l, m] and [m+1, r]
        luckyValue += calculateLuckyValue(l, m, k);
        luckyValue += calculateLuckyValue(m + 1, r, k);
    }

    // Store the computed value in the cache
    memo[key] = luckyValue;
    return luckyValue;
}

int main() {
    int t;
    cin >> t; // Number of test cases
    
    // Process each test case
    for (int i = 0; i < t; i++) {
        long long n, k;
        cin >> n >> k;
        // Clear memo before each test case to avoid retaining data from previous cases
        memo.clear();
        cout << calculateLuckyValue(1, n, k) << endl;
    }
    
    return 0;
}
