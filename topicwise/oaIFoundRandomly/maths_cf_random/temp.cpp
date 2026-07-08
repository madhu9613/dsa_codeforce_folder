#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to hold item properties
struct Item {
    int t;  // time to save
    int d;  // deadline (burns completely)
    int p;  // value
    int id; // original 1-based index
};

// Sort items by deadline in ascending order
bool compareItems(const Item& a, const Item& b) {
    return a.d < b.d;
}

int main() {
    // Optimize standard I/O operations for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<Item> items(n);
    for (int i = 0; i < n; ++i) {
        cin >> items[i].t >> items[i].d >> items[i].p;
        items[i].id = i + 1;
    }

    // Step 1: Sort items by their burn time
    sort(items.begin(), items.end(), compareItems);

    // Step 2: DP Initialization
    // Maximum possible deadline is 2000 according to constraints
    int max_d = 2000;
    
    // dp[i][j] stores the max value considering first i items, taking exactly j seconds
    vector<vector<int>> dp(n + 1, vector<int>(max_d + 1, 0));

    // Step 3: Populate the DP table
    for (int i = 1; i <= n; ++i) {
        int current_t = items[i - 1].t;
        int current_d = items[i - 1].d;
        int current_p = items[i - 1].p;

        for (int j = 0; j <= max_d; ++j) {
            // Base case: Don't take the current item
            dp[i][j] = dp[i - 1][j];

            // If taking the item is valid (time spent is strictly less than deadline)
            if (j >= current_t && j < current_d) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - current_t] + current_p);
            }
        }
    }

    // Step 4: Find the maximum value and the time it took
    int max_val = 0;
    int best_time = 0;
    for (int j = 0; j <= max_d; ++j) {
        if (dp[n][j] > max_val) {
            max_val = dp[n][j];
            best_time = j;
        }
    }

    // Step 5: Backtrack to find which items were selected
    vector<int> saved_items;
    int curr_time = best_time;
    
    for (int i = n; i > 0; --i) {
        // If the value changed from the previous row, we took this item
        if (dp[i][curr_time] != dp[i - 1][curr_time]) {
            saved_items.push_back(items[i - 1].id);
            curr_time -= items[i - 1].t; // Subtract the time taken by this item
        }
    }

    // Since we backtracked from n down to 1, the order is reversed
    reverse(saved_items.begin(), saved_items.end());

    // Output results
    cout << max_val << "\n";
    cout << saved_items.size() << "\n";
    for (int i = 0; i < saved_items.size(); ++i) {
        cout << saved_items[i] << (i == saved_items.size() - 1 ? "" : " ");
    }
    cout << "\n";

    return 0;
}