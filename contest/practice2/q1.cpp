/*
queation 1
*/
#include <iostream>
using namespace std;

void solve() {
    int t;
    cin >> t;  
    while (t--) {
        int n, k;
        cin >> n >> k;  
        
        int start = max(1, n - k + 1);
        
        long long total_clusters = (long long)n * (n + 1) / 2 - (long long)(start - 1) * start / 2;
        
        if (total_clusters % 2 == 0)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}

int main() {
    solve();  
    return 0;
}
