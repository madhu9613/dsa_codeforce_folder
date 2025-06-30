#include <iostream>
#include <string>
#include <climits>
using namespace std;

int f(const string &a, const string &b) {
    int count = 0;
    for (int i = 0; i < a.size(); ++i)
        if (a[i] == b[i]) count++;
    return count;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string l, r;
        cin >> l >> r;
        int n = l.size();
        int min_val = INT_MAX;

        for (int i = 0; i < n; ++i) {
            string x = l;

            for (char d = '0'; d <= '9'; ++d) {
                x[i] = d;
                for (int j = i + 1; j < n; ++j) x[j] = '0'; // make minimal x
                if (x >= l && x <= r) {
                    int fx = f(l, x) + f(x, r);
                    min_val = min(min_val, fx);
                }
            }
            if (l[i] != r[i]) break; // No need to go further after first mismatch
        }

        min_val = min(min_val, f(l, l) + f(l, r));
        min_val = min(min_val, f(r, r) + f(l, r));

        cout << min_val << "\n";
    }
    return 0;
}
