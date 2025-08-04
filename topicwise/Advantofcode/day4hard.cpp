#include <bits/stdc++.h>
using namespace std;

#define pb push_back
vector<string> grid;
int n, m;

bool isXMAS(int i, int j) {
    if (i + 2 >= n || j - 1 < 0 || j + 1 >= m) return false;

    char tl = grid[i][j - 1];
    char tr = grid[i][j + 1];
    char mid = grid[i + 1][j];
    char bl = grid[i + 2][j - 1];
    char br = grid[i + 2][j + 1];

    string diag1 = {tl, mid, br};
    string diag2 = {tr, mid, bl};

    return (diag1 == "MAS" || diag1 == "SAM") && (diag2 == "MAS" || diag2 == "SAM");
}

void solve() {
    string line;
    while (cin >> line) {
        grid.pb(line);
    }

    n = grid.size();
    if (n == 0) {
        cout << 0 << '\n';
        return;
    }

    m = grid[0].size();
    int c = 0;

    for (int i = 0; i <= n - 3; ++i) {
        for (int j = 1; j <= m - 2; ++j) {
            if (isXMAS(i, j)) {
                c++;
            }
        }
    }

    cout << c << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
