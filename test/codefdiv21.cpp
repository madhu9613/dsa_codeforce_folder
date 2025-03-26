#include <iostream>
#include <string>
using namespace std;

void solve() {
    int t;
    cin >> t;  
    while (t--) {
        string s;
        cin >> s;  
        
        bool found = false;
        
         
        for (int i = 0; i < s.size(); ++i) {
            if (i + 1 < s.size() && s[i] == s[i + 1]) {
                cout << s.substr(i, 2) << endl;
                found = true;
                break;
            }
            if (i + 2 < s.size() && s[i] != s[i + 1] && s[i] != s[i + 2] && s[i + 1] != s[i + 2]) {
                cout << s.substr(i, 3) << endl;
                found = true;
                break;
            }
        }
        
        if (!found) {
            cout << -1 << endl;
        }
    }
}

int main() {
    solve();  
    return 0;
}
