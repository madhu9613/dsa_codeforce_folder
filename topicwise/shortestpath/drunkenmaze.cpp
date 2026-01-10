// https://codeforces.com/problemset/problem/2041/D

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define max3(a, b, c) max(max(a, b), c)
#define max4(a, b, c, d) max(max(a, b), max(c, d))
#define pii pair<int, int>
#define pll pair<ll, ll>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl '\n'

struct state
{
    int x, y, dir, cnt, dist;
};

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    for (int i = 0; i < n; i++)
        cin >> grid[i];

    int sx, sy, tx, ty;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 'S')
            {
                sx = i;
                sy = j;
            }
            if (grid[i][j] == 'T')
            {
                tx = i;
                ty = j;
            }
        }
    }

    // vis[x][y][dir][cnt]
    vector<vector<array<array<bool, 4>, 4>>> vis(
        n, vector<array<array<bool, 4>, 4>>(m));

    queue<state> q;

    for (int d = 0; d < 4; d++)
    {
        int nx = sx + dx[d];
        int ny = sy + dy[d];

        if (nx < 0 || nx >= n || ny < 0 || ny >= m)
            continue;
        if (grid[nx][ny] == '#')
            continue;

        vis[nx][ny][d][1] = true;
        q.push({nx, ny, d, 1, 1});
    }

    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();

        if (cur.x == tx && cur.y == ty)
        {
            cout << cur.dist << endl;
            return;
        }

        for (int d = 0; d < 4; d++)
        {
            int nx = cur.x + dx[d];
            int ny = cur.y + dy[d];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (grid[nx][ny] == '#')
                continue;

            if (d == cur.dir)
            {
                if (cur.cnt == 3)
                    continue;
                if (!vis[nx][ny][d][cur.cnt + 1])
                {
                    vis[nx][ny][d][cur.cnt + 1] = true;
                    q.push({nx, ny, d, cur.cnt + 1, cur.dist + 1});
                }
            }
            else
            {
                if (!vis[nx][ny][d][1])
                {
                    vis[nx][ny][d][1] = true;
                    q.push({nx, ny, d, 1, cur.dist + 1});
                }
            }
        }
    }

    cout << -1 << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
