#include <bits/stdc++.h>
using namespace std;
 
const int MAX_BITS = 30;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int &x : a) cin >> x;
 
        vector<int> bitCount(MAX_BITS, 0);
 
        for (int x : a) {
            for (int b = 0; b < MAX_BITS; ++b) {
                if (x & (1 << b)) {
                    bitCount[b]++;
                }
            }
        }
 
        vector<int> result;
 
        // Try all k from 1 to n
        for (int k = 1; k <= n; ++k) {
            bool ok = true;
            for (int b = 0; b < MAX_BITS; ++b) {
                if (bitCount[b] % k != 0) {
                    ok = false;
                    break;
                }
            }
            if (ok) result.push_back(k);
        }
 
        for (int k : result) cout << k << ' ';
        cout << '\n';
    }
    return 0;
}