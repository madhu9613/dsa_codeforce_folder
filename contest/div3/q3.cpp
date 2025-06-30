#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int n;
    unsigned int x;
    cin >> n >> x;

    vector<unsigned int> a;
    unsigned int current_or = 0;
    
    // Step 1: Pick numbers that contribute to x without exceeding it
    for (unsigned int i = 0; i < (1 << 30) && a.size() < n; i++) {
        if ((current_or | i) <= x) {
            a.push_back(i);
            current_or |= i;
        }
    }

    // Step 2: Ensure OR condition holds by adjusting last element if needed
    if (current_or != x) {
        a.back() |= (x ^ current_or);
    }

    // Step 3: If we have fewer than n elements, fill the rest with 0s
    while (a.size() < n) {
        a.push_back(0);
    }

    // Print the resulting array
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
