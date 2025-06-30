/*

QUEATION NO 1
I CAN  USE BRUTE FORCE METHOD 
*/
#include<bits/stdc++.h>
using namespace std;

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        unordered_map<int, vector<int>> rm;

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            int remainder = a[i] % k;
            rm[remainder].push_back(i + 1); 
        }

        bool found = false;
        for (const auto& [remainder, indices] : rm) {
            if (indices.size() == 1) {
                cout << "YES\n" << indices[0] << "\n";
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "NO\n";
        }
    }
}

int main() {
   ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
