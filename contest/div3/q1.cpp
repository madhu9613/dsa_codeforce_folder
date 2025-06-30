#include <iostream>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    long long dash = 0, under = 0;

   
    for (char c : s) {
        if (c == '-') dash++;
        else if (c == '_') under++;
    }

    if (dash < 2 || under == 0) {
        cout << 0 << endl;
        return;
    }

    long long left = dash / 2;
    long long right = dash - left; 

    cout << (left * right * under) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
