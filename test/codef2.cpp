#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int t;
    cin >> t; // Number of test cases

    while (t--) {
        int n;
        cin >> n; // Length of the sequence

        vector<int> sequence;
        int current = 1;

        for (int i = 1; i <= n; ++i) {
            sequence.push_back(current);
            current += 2; 
            if (current > 100) current = 1; 
        }

        // Output the sequence
        for (int num : sequence) {
            cout << num << " ";
        }
        cout << endl;
    }
}

int main() {
    solve();
    return 0;
}
