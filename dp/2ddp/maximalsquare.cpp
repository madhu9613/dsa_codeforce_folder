/**its a important queation
 * Given a binary matrix mat, find out the maximum length of a side of a square sub-matrix with all 1s.
 *
 */
#include <bits/stdc++.h>
using namespace std;
int solve(int i, int j, vector<vector<int>> &mat, int &maxi)
{
    if (i >= mat.size() || j >= mat[0].size())
    {
        return 0;
    }

    int right = solve(i + 1, j, mat, maxi);
    int down = solve(i, j + 1, mat, maxi);
    int diagonal = solve(i + 1, j + 1, mat, maxi);
    if (mat[i][j] == 1)
    {

        int ans = 1 + min(right, down, diagonal); // from right ,left and down how many matrix with 1 can be formed +1 for as if we consider the current square
        maxi = max(maxi, ans);
        return ans;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(m, 0));
    vector<vector<int>> dp(n, vector<int>(m, -1));
    for (int i = 0; i < n * m; i++) // effective way to take input for 2d arrey flatten 2d arreyy input;
    {
        cin >> mat[i / m][i % m];
    }

    // int ans=solve(mat,0,0);
    int maxi = INT_MIN;
    int ans = solve(0, 0, mat, maxi);
    cout << maxi << endl;
    return 0;
}