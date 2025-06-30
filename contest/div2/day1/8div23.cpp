#include <bits/stdc++.h>
using namespace std;

// Helper to generate segments for maximum S(p)
vector<int> generateSegment(int n, long long k) {
    vector<int> result;
    int current = 1;

    while (n > 0) {
        // Determine the size of the next segment
        int segmentSize = min(n, 1 + (int)sqrt(2 * k));
        for (int i = 0; i < segmentSize; ++i) {
            result.push_back(current + segmentSize - 1 - i); // Add segment in reverse order
        }
        current += segmentSize;
        k -= segmentSize * (segmentSize - 1) / 2;
        n -= segmentSize;
    }
  
    return result;
}

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        long long k;
        cin >> n >> k;

        // Check if k exceeds number of possible segments
        if (k > (long long)n * (n - 1) / 2 + 1) {
            cout << -1 << "\n";
            continue;
        }

        // Generate the k-th permutation
        vector<int> result = generateSegment(n, k);
        for (int x : result) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
