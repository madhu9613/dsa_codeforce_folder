#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> nums(n);
        map<int, int> freq;

        for (int i = 0; i < n; ++i) {
            cin >> nums[i];
            freq[nums[i]]++;
        }

        bool solved = false;

        for (auto &entry : freq) {
            if (entry.second >= 4) {
                cout << entry.first << " " << entry.first << " " 
                     << entry.first << " " << entry.first << endl;
                solved = true;
                break;
            }
        }
        if (solved) continue;

        vector<int> pairs;
        for (auto &entry : freq) {
            if (entry.second >= 2) {
                pairs.push_back(entry.first);
            }
        }
        if (pairs.size() >= 2) {
            sort(pairs.begin(), pairs.end());
            cout << pairs[0] << " " << pairs[0] << " " 
                 << pairs[1] << " " << pairs[1] << endl;
            continue;
        }

        for (auto &entry : freq) {
            if (entry.second >= 2) {
                int a = entry.first;
                freq[a] -= 2;

                vector<int> remaining_sticks;
                for (auto &rem : freq) {
                    for (int i = 0; i < rem.second; ++i) {
                        remaining_sticks.push_back(rem.first);
                    }
                }

                sort(remaining_sticks.begin(), remaining_sticks.end());

                for (int i = 0; i < remaining_sticks.size() - 1; ++i) {
                    int b = remaining_sticks[i];
                    int c = remaining_sticks[i + 1];

                    if (c - b < 2 * a) {
                        cout << a << " " << a << " " << b << " " << c << endl;
                        solved = true;
                        break;
                    }
                }
                if (solved) break;
            }
        }

        if (!solved) {
            cout << -1 << endl;
        }
    }

    return 0;
}
