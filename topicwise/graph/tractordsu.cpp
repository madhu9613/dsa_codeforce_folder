#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent, sz;
    DSU(int n) {
        parent.resize(n);
        sz.assign(n, 1);
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x) {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }
    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return;
        if (sz[a] < sz[b]) swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
    }
    int size(int x) {
        return sz[find(x)];
    }
};

int n, halfCells;
vector<vector<int>> grid;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

inline int id(int x, int y) { return x * n + y; }

bool check(int diff) {
    DSU dsu(n * n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < 4; k++) {
                int ni = i + dx[k], nj = j + dy[k];
                if (ni >= 0 && ni < n && nj >= 0 && nj < n) {
                    if (abs(grid[i][j] - grid[ni][nj]) <= diff) {
                        dsu.unite(id(i, j), id(ni, nj));
                    }
                }
            }
        }
    }

    for (int i = 0; i < n * n; i++) {
        if (dsu.size(i) >= halfCells) return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("tractor.in", "r", stdin);
    freopen("tractor.out", "w", stdout);

    cin >> n;
    grid.assign(n, vector<int>(n));
    int mn = INT_MAX, mx = INT_MIN;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            mn = min(mn, grid[i][j]);
            mx = max(mx, grid[i][j]);
        }
    }

    halfCells = (n * n + 1) / 2;

    int l = 0, r = mx - mn, ans = -1;
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (check(m)) {
            ans = m;
            r = m - 1;
        } else {
            l = m + 1;
        }
    }

    cout << ans << "\n";
    return 0;
}
