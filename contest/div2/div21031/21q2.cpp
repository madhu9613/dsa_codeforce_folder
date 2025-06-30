#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;
// using int64 = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
       long long s;
        cin >> n >> s;
        long long count = 0;
        for (int i = 0; i < n; i++) {
            int dx, dy;
          long long x, y;
            cin >> dx >> dy >> x >> y;
            long long d = (dx * x - dy * y) % s;
            if (d < 0) d += s;
            if (d == 0)
                count++;
        }
        cout << count << "\n";
    }

    return 0;
}