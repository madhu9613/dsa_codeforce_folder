#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int t;
    cin >> t;  // Read number of test cases
    
    while (t--) {
        int n;
        cin >> n;  // Read the size of the sequence
        vector<int> a(n);
        
        for (int i = 0; i < n; i++) {
            cin >> a[i];  // Read the sequence
        }
        
        bool possible = true;
        
        // Traverse through the sequence and check if we can make it non-decreasing
        for (int i = 1; i < n; i++) {
            if (a[i] < a[i - 1]) {
                if (a[i] < a[i - 1]) {
                    possible = false;
                    break;
                }
            }
        }
        
        // Output the result for this test case
        if (possible) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}

int main() {
    solve();  // Call the solve function to process the input and output
    return 0;
}
