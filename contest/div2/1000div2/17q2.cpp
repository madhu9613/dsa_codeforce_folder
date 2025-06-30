#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    
    for (int &x : a) cin >> x;
    
    sort(a.rbegin(), a.rend()); // Sort in descending order
    
    long long sum_k = accumulate(a.begin(), a.begin() + k, 0LL);
    long long max_remaining = *max_element(a.begin() + k, a.end());
    
    cout << sum_k + max_remaining << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}
