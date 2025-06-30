/*

QUEATION NO 2
*/
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int t;
    cin >> t;
    cin.ignore(); 

    while (t--) {
        string input;
        getline(cin, input); 
        
        int n = input.size();
        string result = "";

        for (int i = n - 1; i >= 0; i--) {
            if (input[i] == 'p') {
                result += 'q';
            } else if (input[i] == 'q') {
                result += 'p';
            } else if (input[i] == 'w') {
                result += 'w';
            } else {
                result += input[i]; 
            }
        }

        cout << result << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}

