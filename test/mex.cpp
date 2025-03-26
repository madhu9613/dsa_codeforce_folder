#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve(vector<int> &v)
{
    sort(v.begin(), v.end());
   
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a;
        int e;
        for (int i = 0; i < n; i++)
        {
            cin >> e;
            a.push_back(e);
        }

        solve(a);
    }

    return 0;
}