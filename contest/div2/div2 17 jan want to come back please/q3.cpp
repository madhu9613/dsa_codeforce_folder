#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t; 
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> cows(n);
        
        for (int i = 0; i < n; ++i) {
            cows[i].resize(m);
            for (int j = 0; j < m; ++j) {
                cin >> cows[i][j];
            }
            // Sort each row
            sort(cows[i].begin(), cows[i].end());
        }
        
        vector<pair<int, int>> cows_with_min(n);
        for (int i = 0; i < n; ++i) {
            int min_card = *min_element(cows[i].begin(), cows[i].end());
            cows_with_min[i] = {min_card, i};
        }
        
        sort(cows_with_min.begin(), cows_with_min.end());
        
        vector<int> order(n);
        for (int i = 0; i < n; ++i) {
            order[i] = cows_with_min[i].second;
        }
        
        vector<int> merged;
        bool valid = true;
        vector<int> indices(n, 0); 
        int current_top = -1;

        for (int round = 0; round < m; ++round) {
            for (int i = 0; i < n; ++i) {
                int cow_idx = order[i];
                if (indices[cow_idx] < m && cows[cow_idx][indices[cow_idx]] > current_top) {
                    current_top = cows[cow_idx][indices[cow_idx]];
                    indices[cow_idx]++;
                } else {
                    valid = false;
                    break;
                }
            }
            if (!valid) break;
        }

        if (valid) {
            for (int i = 0; i < n; ++i) {
                cout << order[i] + 1 << " ";
            }
            cout << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}
