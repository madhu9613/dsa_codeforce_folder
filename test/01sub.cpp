#include <iostream>
#include <string>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        cout << string(k, '1') + string(n - k, '0') << '\n';
    }
    return 0;
}