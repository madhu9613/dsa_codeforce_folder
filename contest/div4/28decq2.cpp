#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int t;  // Number of test cases
    cin >> t;

    while (t--) {
        int n;  // Number of impressions
        cin >> n;

        vector<pair<pair<int, int>, int>> impressions(n);  // To store (li, ri) and their index
        for (int i = 0; i < n; ++i) {
            cin >> impressions[i].first.first >> impressions[i].first.second;
            impressions[i].second = i;  // Store the index
        }

        // Sort impressions by the left value (li), and if equal, by the right value (ri)
        sort(impressions.begin(), impressions.end());

        vector<char> result(n, '0');  // Default to '0' for non-unique
        set<int> used;  // To track used values

        // Try to assign unique values to each impression
        for (auto& imp : impressions) {
            int li = imp.first.first;
            int ri = imp.first.second;
            int idx = imp.second;

            // Find the first available value in the range [li, ri] that is not used
            bool assigned = false;
            for (int val = li; val <= ri; ++val) {
                if (used.find(val) == used.end()) {
                    used.insert(val);  // Mark the value as used
                    result[idx] = '1';  // Mark this impression as unique
                    assigned = true;
                    break;
                }
            }

            // If no valid value was found, it remains '0' (not unique)
        }

        // Output the result as a binary string
        for (char c : result) {
            cout << c;
        }
        cout << endl;
    }

    return 0;
}
