#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int c0 = (n + 3) / 4;
        int c1 = (n + 2) / 4;
        int c2 = (n + 1) / 4;
        int c3 = n / 4;

        if (c0 != c3 || c1 != c2) {
            cout << "Alice" << endl;
        } else {
            cout << "Bob" << endl;
        }
    }
    return 0;
}
