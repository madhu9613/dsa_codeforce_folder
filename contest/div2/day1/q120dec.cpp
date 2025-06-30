/*
    QUEATION NO 1
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t; // Number of test cases
    while (t--) {
        int n;
        cin >> n; // Length of the array
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        // Step 1: Remove leading zeros
        int start = 0, end = n - 1;
        while (start < n && a[start] == 0) start++;
        while (end >= 0 && a[end] == 0) end--;

        // Step 2: Check the subarray
        if (start > end) {
            // The entire array is zeros
            cout << "0\n";
        } else {
            int smallest = *min_element(a.begin() + start, a.begin() + end + 1);
            if (smallest == 0) {
                cout << "2\n";
            } else {
                cout << "1\n";
            }
        }
    }
    return 0;
}
