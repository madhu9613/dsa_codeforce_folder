#include <iostream>
using namespace std;

// Function to calculate the final lucky value for each test case
long long calculate_lucky_value(long long n, long long k) {
    long long lucky_value = 0;
    
    // Use a queue-like process to simulate recursion
    // Initially, we start with the segment [1, n]
    long long l = 1, r = n;
    
    // Iterate until the segment length becomes less than k
    while (l <= r) {
        // If the length of the segment is smaller than k, stop the observation
        if (r - l + 1 < k) {
            break;
        }

        // Find the middle element
        long long m = (l + r) / 2;
        
        // Add middle element value to the lucky value
        lucky_value += m;
        
        // Split the segment into two parts:
        // - Left part: [l, m-1]
        // - Right part: [m+1, r]
        
        // Move to the next part by narrowing down the segment
        l = m + 1;  // Right part (m+1 to r)
        r = m - 1;  // Left part (l to m-1)
    }
    
    return lucky_value;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        long long n, k;
        cin >> n >> k;
        
        // For each test case, calculate and print the result
        cout << calculate_lucky_value(n, k) << endl;
    }
    
    return 0;
}
