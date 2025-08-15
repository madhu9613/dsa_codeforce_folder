#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>

int n;
vector<vector<int>> grid;
vector<vector<bool>> visited;
int halfCells;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool bfs(int diff) {
    visited.assign(n, vector<bool>(n, false));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j]) {
                queue<pii> q;
                q.push({i, j});
                visited[i][j] = true;
                int cnt = 1;

                while (!q.empty()) {
                    auto [x, y] = q.front();
                    q.pop();
                    for (int d = 0; d < 4; d++) {
                        int nx = x + dx[d], ny = y + dy[d];
                        if (nx >= 0 && nx < n && ny >= 0 && ny < n &&
                            !visited[nx][ny] &&
                            abs(grid[nx][ny] - grid[x][y]) <= diff) {
                            visited[nx][ny] = true;
                            q.push({nx, ny});
                            cnt++;
                        }
                    }
                }
                if (cnt >= halfCells) return true;
            }
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

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

    int ans = INT_MAX;
    int l = 0, r = mx - mn; 
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (bfs(m)) {
            ans = m;
            r = m - 1;
        } else {
            l = m + 1;
        }
    }

    cout << ans << "\n";
}
