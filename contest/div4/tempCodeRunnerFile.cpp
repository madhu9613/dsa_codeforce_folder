#include <iostream>
#include <vector>
using namespace std;

// Function to calculate the sum of numbers from 1 to n (inclusive)
long long sumUpTo(long long n) {
    return n * (n + 1) / 2;
}

// Function to calculate lucky value for a segment [l, r] with minimum length k
long long calculateLuckyValue(long long l, long long r, long long k) {
    if (r - l + 1 < k) return 0; // If the length of the segment is less than k, return 0
    
    long long luckyValue = 0;
    
    while (l <= r) {
        long long length = r - l + 1; // Current segment length

        if (length < k) {
            break; // If the segment length is smaller than k, stop
        }

        long long mid = (l + r) / 2; // Middle element
        
        // Add the middle element if the segment length is odd
        if (length % 2 == 1) {
            luckyValue += mid;
        }

        // Now, process both halves of the segment
        r = mid - 1; // Move the right pointer to the left part
    }

    return luckyValue;
}

int main() {
    int t;
    cin >> t; // Number of test cases
    vector<long long> results(t);
    
    for (int i = 0; i < t; i++) {
        long long n, k;
        cin >> n >> k;
        results[i] = calculateLuckyValue(1, n, k);
    }
    
    // Output results
    for (const auto& res : results) {
        cout << res << endl;
    }
    return 0;
}
