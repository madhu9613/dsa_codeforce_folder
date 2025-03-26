#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


bool is_valid(long long x, long long y) {
    long long z = x ^ y;
    return (x % z == 0) || (y % z == 0);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long x, m;
        cin >> x >> m;

        int count = 0;
        for (long long y = 1; y <= m; ++y) {
            if (y != x && is_valid(x, y)) {
                count++;
            }
        }
        cout << count << endl;
    }

    return 0;
}
