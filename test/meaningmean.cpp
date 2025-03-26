#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve(vector<int> &v)
{
    sort(v.begin(), v.end());
    while (v.size() > 1)
    {
        int x = v[0];
        int y = v[1];
        int new_val = (x + y) / 2;
        v.erase(v.begin());
        v.erase(v.begin());
        v.push_back(new_val);
        sort(v.begin(), v.end());
    }
    cout << v[0] << endl;
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