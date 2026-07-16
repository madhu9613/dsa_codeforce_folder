#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n, m;
vector<string> grid;

// DFS returns true if a path to (n-1, m-1) is found
bool dfs(int r, int c)
{
    if (r >= n || c >= m || grid[r][c] == '#')
    {
        return false;
    }
    if (r == n - 1 && c == m - 1)
    {
        return true;
    }

    // Mark the cell as visited/blocked to avoid revisiting
    // and to block it for the second DFS pass.
    if (r != 0 || c != 0)
    {
        grid[r][c] = '#';
    }

    // Try moving Down, then Right
    if (dfs(r + 1, c))
        return true;
    if (dfs(r, c + 1))
        return true;

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> n >> m))
        return 0;

    grid.resize(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> grid[i];
    }

    // First DFS pass
    if (!dfs(0, 0))
    {
        cout << 0 << "\n";
        return 0;
    }

    // Second DFS pass (using the updated grid where the first path is blocked)
    if (!dfs(0, 0))
    {
        cout << 1 << "\n";
    }
    else
    {
        cout << 2 << "\n";
    }

    return 0;
}