#include <iostream>
#include <vector>
#include <stack>
using namespace std;

bool knows(vector<vector<int>>& m, int a, int b)
{
    return m[a][b] == 1;
}

void celebrity(vector<vector<int>>& m, int n)
{
    stack<int> s;

    // Push all elements into the stack
    for (int i = 0; i < n; i++)
    {
        s.push(i);
    }

    // Find potential celebrity
    while (s.size() > 1)
    {
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();

        if (knows(m, a, b))
        {
            // If a knows b, a can't be a celebrity, push b
            s.push(b);
        }
        else
        {
            // If a doesn't know b, b can't be a celebrity, push a
            s.push(a);
        }
    }

    // Single element in the stack is the potential celebrity
    int candidate = s.top();

    // Check row of candidate: All should be 0
    bool rowCheck = true;
    for (int i = 0; i < n; i++)
    {
        if (m[candidate][i] != 0)
        {
            rowCheck = false;
            break;
        }
    }

    // Check column of candidate: All should be 1 except for candidate's own row
    bool colCheck = true;
    for (int i = 0; i < n; i++)
    {
        if (i != candidate && m[i][candidate] != 1)
        {
            colCheck = false;
            break;
        }
    }

    // If both row and column conditions are satisfied, candidate is a celebrity
    if (rowCheck && colCheck)
    {
        cout << candidate << " is the celebrity\n";
    }
    else
    {
        cout << -1 << " No celebrity found\n";
    }
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> m(n, vector<int>(n));

    // Input the matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> m[i][j];
        }
    }

    celebrity(m, n);
    return 0;
}
