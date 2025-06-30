#include <iostream>
#include <vector>
using namespace std;

int maxSumClimbingStairs(vector<int>& arr) {
    int n = arr.size();
    if (n == 0) return 0;
    if (n == 1) return arr[0];

    vector<int> dp(n, 0);
    dp[0] = arr[0];
    dp[1] = arr[0] + arr[1];

    for (int i = 2; i < n; i++) {
        dp[i] = arr[i] + max(dp[i-1], dp[i-2]);
    }

    return max(dp[n-1], dp[n-2]);  // Answer
}

int main() {
    vector<int> arr = {1,2};  
    cout << "Maximum sum: " << maxSumClimbingStairs(arr) << endl;
    return 0;
}
