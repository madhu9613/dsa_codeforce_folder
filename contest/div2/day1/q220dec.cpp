#include <iostream>
#include <vector>
#include <set>
using namespace std;

// Function to calculate MEX (Minimum Excluded Value)
int calculate_mex(const set<int>& assigned) {
    int mex = 0;
    while (assigned.find(mex) != assigned.end()) {
        mex++;
    }
    return mex;
}

void solve() {
    int t;
    cin >> t; // Number of test cases
    while (t--) {
        int n, x, y;
        cin >> n >> x >> y;

        vector<vector<int>> friends(n + 1);
        for (int i = 1; i <= n; i++) {
            friends[i].push_back((i == 1) ? n : i - 1); 
            friends[i].push_back((i == n) ? 1 : i + 1); 
        }
        friends[x].push_back(y);
        friends[y].push_back(x);

        vector<int> a(n + 1, -1);

        for (int i = 1; i <= n; i++) {
            set<int> assigned_values;
            for (int f : friends[i]) {
                if (a[f] != -1) {
                    assigned_values.insert(a[f]);
                }
            }
            a[i] = calculate_mex(assigned_values);
        }

        for (int i = 1; i <= n; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
