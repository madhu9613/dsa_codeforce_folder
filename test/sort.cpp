#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // 2D vector
    vector<vector<int>> vec = {
        {5, 2, 9, 1},
        {4, 3, 7, 6},
        {8, 0, 3, 5}
    };

    // Sorting rows based on the first element of each row
    sort(vec.begin(), vec.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];  // Compare first element of each row
    });

    // Printing the sorted 2D vector
    for (const auto& row : vec) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    
    return 0;
}
