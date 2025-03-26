/*
brute force method...
Given an array of integers, find the Kth largest sum subarray 
For example, given the array [1, -2, 3, -4, 5] and K = 2, the 2nd largest sum subarray would be [3, -4, 5],
 which has a sum of 4.

Please note that a subarray is the sequence of consecutive elements of the array.

*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums;                                             
    for (int i = 0; i < n; i++) {
        int data;
        cin >> data;
        nums.push_back(data);
    }

    int k;
    cin >> k;

    vector<int> sum_of_subarrays;

    // Generate all subarray sums
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += nums[j]; // Correctly accumulate nums[j]
            sum_of_subarrays.push_back(sum);
        }
    }

    // Sort the sums
    sort(sum_of_subarrays.begin(), sum_of_subarrays.end());

    // Retrieve the Kth largest sum
    int n1 = sum_of_subarrays.size();
    int ans = sum_of_subarrays[n1 - k];
    cout << ans << endl;

    return 0;
}
