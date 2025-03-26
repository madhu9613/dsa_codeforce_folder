/** Envelops We can fixed one envelop inside another one if and only if its both wudth and height is smaller than other */
#include <bits/stdc++.h>
using namespace std;
int solve(vector<vector<int>> &envelop)
{
    if (envelop.empty())
    {
        return 0;
    }

    sort(envelop.begin(), envelop.end(), [](const vector<int> &a, const vector<int> &b)
         {
            if (a[0] == b[0]) return a[1] > b[1]; 
            return a[0] < b[0]; });

    // find longest increasing subsequence in height colom::
    vector<int> ans;

    for (auto &height : envelop)
    {

        auto it = lower_bound(ans.begin(), ans.end(), height[1]);
        if (it == ans.end())
        {
            ans.push_back(height[1]);
        }
        else
        {

            *it = height[1];
        }
    }
    return ans.size();
}
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> envelop(n, vector<int>(2));
    for (int i = 0; i < n; i++)
    {
        cin >> envelop[i][0] >> envelop[i][1];
    }

    int ans=solve(envelop);
    cout<<ans;

    return 0;
}