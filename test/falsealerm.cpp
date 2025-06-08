#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        
        for(int i = 0; i < n; ++i)
            cin >> a[i];
        
        bool used = false;
        bool possible = true;

        for(int i = 0; i < n; ++i) {
            if(a[i] == 0) {
                if(used) x--;
            }
            else { // a[i] == 1
                if(!used) {
                    x--;
                    used = true;
                } else {
                    if(x > 0) x--;
                    else {
                        possible = false;
                        break;
                    }
                }
            }
        }

        cout << (possible ? "YES" : "NO") << endl;
    }

    return 0;
}
