#include <iostream>
using namespace std;

bool can_tile(int w, int h, int a, int b, int x1, int y1, int x2, int y2) {
    int tx1 = x1 - (x1 % a);
    int ty1 = y1 - (y1 % b);
    int tx2 = x2 - (x2 % a);
    int ty2 = y2 - (y2 % b);

    // Check if both tiles fit inside the rectangle
    bool fits1 = (tx1 + a <= w) && (ty1 + b <= h);
    bool fits2 = (tx2 + a <= w) && (ty2 + b <= h);

    if (!fits1 || !fits2) return false;

    // Check that tiles don't overlap
    bool no_overlap = (tx1 + a <= tx2) || (tx2 + a <= tx1) ||
                      (ty1 + b <= ty2) || (ty2 + b <= ty1);

    return no_overlap;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int w, h, a, b;
        int x1, y1, x2, y2;
        cin >> w >> h >> a >> b;
        cin >> x1 >> y1 >> x2 >> y2;

        if (can_tile(w, h, a, b, x1, y1, x2, y2))
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}
