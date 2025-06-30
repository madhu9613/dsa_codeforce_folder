#include <iostream>
#include <string>
using namespace std;

void solve() {
    int t; // Number of test cases
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        // Initialize variables to track positions of 'p' and 's'
        int lastP = -1, firstS = n + 1;

        // Traverse through the string to find the last 'p' and first 's'
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'p') {
                lastP = i;
            }
            if (s[i] == 's' && firstS == n + 1) {
                firstS = i;
            }
        }

        // If the last 'p' is before the first 's', it's a valid permutation
        if (lastP < firstS) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}

int main() {
    solve();
    return 0;
}
