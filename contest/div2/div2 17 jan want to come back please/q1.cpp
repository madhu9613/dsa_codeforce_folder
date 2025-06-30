#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k; 

        vector<int> x(n);
        unordered_map<int, int> freq;

        for (int i = 0; i < n; i++) {
            cin >> x[i];
            freq[x[i]]++;
        }

        int score = 0;

        for (const auto& [a, count_a] : freq) {
            int b = k - a;
            if (freq.count(b)) {
                int pair_count = min(freq[a], freq[b]);
                if (a == b) pair_count /= 2; 
                score += pair_count;

                freq[a] -= pair_count;
                freq[b] -= pair_count;
            }
        }

        cout << score << endl; 
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
