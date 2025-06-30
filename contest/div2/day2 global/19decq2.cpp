#include <iostream>
#include <vector>
#include <set>
using namespace std;

void solve() {
    int t;
    cin >> t; 
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> p(n, 0); 
        set<int> unused; 

        for (int i = 1; i <= n; ++i) {
            unused.insert(i);
        }

        
        int current_smallest = 1;
        for (int pos = k; pos <= n; pos += k) {
            p[pos - 1] = current_smallest++;
            unused.erase(p[pos - 1]);
        }

        
        for (int i = 0; i < n; ++i) {
            if (p[i] == 0) {
                p[i] = *unused.begin();
                unused.erase(unused.begin());
            }
        }

        
        for (int i = 0; i < n; ++i) {
            cout << p[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
