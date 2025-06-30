#include <iostream>
#include <vector>
using namespace std;

// Function to calculate minimum operations for a single test case
int calculate_operations(vector<vector<int>>& matrix, int n) {
    int operations = 0;

    // Traverse from bottom-right to top-left diagonal-wise
    for (int i = n - 1; i >= 0; --i) {
        for (int j = n - 1; j >= 0; --j) {
            // We only care about the diagonals, i.e., (i, j) where i == j
            if (i == j && matrix[i][j] < 0) {
                // We need to apply enough magic operations to make this element non-negative
                int add = -matrix[i][j];  // The amount we need to increase
                operations += add;  // Count this as the required number of operations
                matrix[i][j] += add;  // Adjust the matrix element
            }
        }
    }

    return operations;
}

int main() {
    int t;  // Number of test cases
    cin >> t;

    while (t--) {
        int n;  // Size of the matrix
        cin >> n;
        vector<vector<int>> matrix(n, vector<int>(n));

        // Read the matrix input
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> matrix[i][j];
            }
        }

        // Calculate the number of operations needed for this test case
        int result = calculate_operations(matrix, n);

        // Output the result for this test case
        cout << result << endl;
    }

    return 0;
}
