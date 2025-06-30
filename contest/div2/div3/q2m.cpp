#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }

        bool possible = true;  
        for (int i = 0; i < n; i++) {
            if (b[i] > a[i]) {  
                int needed = b[i] - a[i];
                for (int j = 0; j < n; j++) {
                    if (i != j) {  
                        if (a[j] - b[j] < needed) {  
                            cout << "NO" << endl;
                            possible = false;
                            break;
                        }
                    }
                }
                if (!possible) break;  
            }
        }

        if (possible) {
            cout << "YES" << endl;
        }
    }

    return 0;
}