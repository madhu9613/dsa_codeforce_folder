#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        set<int> s;
        unordered_map<int, int> freq;

        // Read the elements and populate the set and frequency map
        for (int i = 0; i < n; i++) {
            int data;
            cin >> data;
            s.insert(data);  // Insert unique elements into the set
            freq[data]++;    // Track frequency of each element
        }

        int maxCount = 0;

        // Insert all elements from the set into a vector for sliding window
        vector<int> unique_elements(s.begin(), s.end());

        // Sliding window on the unique elements
        for (int i = 0; i <= unique_elements.size() - k; i++) {
            int currentCount = 0;
            bool mark = true; // to track if we need to stop counting
            
            // Calculate the frequency sum of the window of size k
            for (int j = i; j < i + k; j++) {
                if (j > i && unique_elements[j] != unique_elements[j - 1] + 1) {
                    mark = false;  // stop counting if not consecutive
                    break; // Break out of the loop to reset the count
                }
                if (mark) {
                    currentCount += freq[unique_elements[j]];
                }
            }

            // Update the maxCount if the current window sum is greater
            maxCount = max(maxCount, currentCount);
        }

        cout << maxCount << endl;
    }
    return 0;
}
