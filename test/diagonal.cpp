#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;  // Number of test cases
    
    while (t--) {
        int n, k;
        cin >> n >> k;  // Side of the board and number of chips
        
        // Case when there are no chips
        if (k == 0) {
            cout << 0 << endl;
            continue;
        }
        
        // Calculate the minimum number of occupied diagonals
        int full_diags = k / n;      // Full diagonals (completely filled)
        int remaining = k % n;       // Chips that remain after filling full diagonals
        
        int result = full_diags + (remaining > 0 ? 1 : 0);  // Occupied diagonals

        cout << result << endl;
    }
    
    return 0;
}
