#include <iostream>
#include <string>
#include <vector>
using namespace std;

void solve() {
    int t;
    cin >> t;
    vector<string> results;

    while (t--) {
        string s;
        cin >> s;
        int n = s.length();
        
        int k = -1; 
        int x = 0;  
        
        for (int i = 0; i < n; ++i) {
            if (s[i] == '0') {
                if (k == -1) {
                    k = i; 
                }
                x++;  
            } else if (k != -1) {
                break; 
            }
        }

        if (k == -1) {
            results.push_back("1 " + to_string(n) + " 1 1");
        } else {
            k++;
            
            if (k - x >= 1) {
                results.push_back("1 " + to_string(n) + " " + to_string(k - x) + " " + to_string(n - x ));
            } else {
                results.push_back("1 " + to_string(n) + " 1 " + to_string(n - k + 1));
            }
        }
    }
    
    for (const string& res : results) {
        cout << res << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
