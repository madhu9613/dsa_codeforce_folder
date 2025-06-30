#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> row, left, right;

        for (int i = 1; i <= n; ++i) {
            int k = (n - i); // how much to rotate row i to the left

            if (k == 0) continue; // no rotation needed

            // rotate left by k using 3 reversals
            row.push_back(i);
            left.push_back(1);
            right.push_back(k);

            row.push_back(i);
            left.push_back(k + 1);
            right.push_back(n);

            row.push_back(i);
            left.push_back(1);
            right.push_back(n);
        }

        cout << row.size() << "\n";
        for (int i = 0; i < row.size(); ++i) {
            cout << row[i] << " " << left[i] << " " << right[i] << "\n";
        }
    }

    return 0;
}
