// #include <bits/stdc++.h>
// using namespace std;

// int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
// int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

// int n, m;
// vector<string> grid;
// vector<vector<int>> dp;

// int dfs(int x, int y) {
//     if (dp[x][y] != -1) return dp[x][y];
//     int maxLen = 1;
//     for (int d = 0; d < 8; d++) {
//         int nx = x + dx[d];
//         int ny = y + dy[d];
//         if (nx >= 0 && nx < n && ny >= 0 && ny < m &&
//             grid[nx][ny] == grid[x][y] + 1) {
//             maxLen = max(maxLen, 1 + dfs(nx, ny));
//         }
//     }
//     return dp[x][y] = maxLen;
// }

// void solve() {
//     int t = 1;
//     while (cin >> n >> m, n || m) {
//         grid.resize(n);
//         dp.assign(n, vector<int>(m, -1));
//         for (int i = 0; i < n; ++i) {
//             cin >> grid[i];
//         }

//         int res = 0;
//         for (int i = 0; i < n; ++i) {
//             for (int j = 0; j < m; ++j) {
//                 if (grid[i][j] == 'A') {
//                     res = max(res, dfs(i, j));
//                 }
//             }
//         }

//         cout << "Case " << t++ << ": " << res << '\n';
//     }
// }
// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     solve();
//     return 0;
// }

// a bfs version also

// #include <bits/stdc++.h>
// using namespace std;

// #define ll long long
// #define pb push_back
// #define vi vector<int>
// #define vll vector<ll>
// #define max3(a, b, c) max(max(a, b), c)
// #define max4(a, b, c, d) max(max(a, b), max(c, d))
// #define pii pair<int, int>
// #define all(x) (x).begin(), (x).end()
// #define endl '\n'

// ll gcd(ll a, ll b)
// {
//     return b == 0 ? a : gcd(b, a % b);
// }
// const int MOD = 1e9 + 7;
// const int INF = INT_MAX;
// int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
// int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

// int n, m;
// vector<string> grid;
// vector<vector<int>> dp;

// int bfs(int x, int y)
// {
//     queue<pair<pair<int, int>, int>> q;
//     vector<vector<bool>> visited(n, vector<bool>(m, false));

//     q.push({{x, y}, 1});
//     visited[x][y] = true;
//     int maxlen = 1;
//     while (!q.empty())
//     {
//         auto [cell, len] = q.front();
//         q.pop();
//         int cx = cell.first, cy = cell.second;
//         for (int d = 0; d < 8; d++)
//         {
//             int nx = cx + dx[d];
//             int ny = cy + dy[d];

//             if (nx >= 0 && ny >= 0 && nx < n && ny < m && !visited[nx][ny] && grid[nx][ny] == grid[cx][cy] + 1)
//             {
//                 visited[nx][ny] = true;
//                 q.push({{nx, ny}, len + 1});
//                 maxlen = max(maxlen, len + 1);
//             }
//         }
//     }
//     return maxlen;
// }

// void solve()
// {
//     int t = 1;
//     while (cin >> n >> m && (n || m))
//     {
//         grid.resize(n);

//         for (int i = 0; i < n; i++)
//         {
//             cin >> grid[i];
//         }
//         int maxpath = 0;
//         for (int i = 0; i < n; i++)
//         {
//             for (int j = 0; j < m; j++)
//             {
//                 if (grid[i][j] == 'A')
//                 {
//                     maxpath = max(maxpath, bfs(i, j));
//                 }
//             }
//         }
//         cout << "Case " << t++ << ": " << maxpath << endl;
//     }
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     int t = 1;
   
//     while (t--)
//         solve();
//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;

int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1}; // 8 directions
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main() {
    int tc = 1;
    while (true) {
        int h, w;
        cin >> h >> w;
        if (h == 0 && w == 0) break;

        vector<string> grid(h);
        for (int i = 0; i < h; ++i)
            cin >> grid[i];

        vector<vector<int>> dist(h, vector<int>(w, 0));
        queue<pair<int, int>> q;

        // Multi-source BFS initialization: all 'A' positions
        for (int i = 0; i < h; ++i)
            for (int j = 0; j < w; ++j)
                if (grid[i][j] == 'A') {
                    q.push({i, j});
                    dist[i][j] = 1; // Starting length from 'A'
                }

        int maxLen = 0;

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            char current = grid[x][y];
            maxLen = max(maxLen, dist[x][y]);

            for (int d = 0; d < 8; ++d) {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (nx >= 0 && nx < h && ny >= 0 && ny < w) {
                    if (grid[nx][ny] == current + 1 && dist[nx][ny] < dist[x][y] + 1) {
                        dist[nx][ny] = dist[x][y] + 1;
                        q.push({nx, ny});
                    }
                }
            }
        }

        cout << "Case " << tc++ << ": " << maxLen << "\n";
    }

    return 0;
}
