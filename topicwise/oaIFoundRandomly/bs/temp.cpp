#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

const int INF = 1e9;
int n, m;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void bfs(const vector<string> &grid, vector<vector<int>> &dist, char state)
{
    queue<pair<int, int>> q;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (grid[i][j] == state)
            {
                dist[i][j] = 0;
                q.push({i, j});
            }
        }
    }

    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] != '#')
            {
                int cost = (grid[nx][ny] == '.') ? 1 : 0;
                if (dist[nx][ny] > dist[x][y] + cost)
                {
                    dist[nx][ny] = dist[x][y] + cost;
                    q.push({nx, ny});
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n; ++i)
        cin >> grid[i];

    vector<vector<int>> d1(n, vector<int>(m, INF)), d2(d1), d3(d1);
    bfs(grid, d1, '1');
    bfs(grid, d2, '2');
    bfs(grid, d3, '3');

    int ans = INF;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (d1[i][j] == INF || d2[i][j] == INF || d3[i][j] == INF)
                continue;

            int current_sum = d1[i][j] + d2[i][j] + d3[i][j];
            // If junction is a '.', we counted it 3 times, need it 1 time: subtract 2
            // If junction is a state cell, we counted it as 0, which is correct
            if (grid[i][j] == '.')
                current_sum -= 2;
            ans = min(ans, current_sum);
        }
    }

    cout << (ans >= INF ? -1 : ans) << endl;
    return 0;
}