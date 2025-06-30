#include <bits/stdc++.h>
using namespace std;

void computeSubarraySums(const vector<int>& arr, set<int>& result) {
    int n = arr.size();
    for (int i = 0; i < n; ++i) {
        int sum = 0;
        for (int j = i; j < n; ++j) {
            sum += arr[j];
            result.insert(sum);
        }
    }
}
void solve()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        vector<int> before, after;
        int xindex = -1;
        int element;
        for (int i = 0; i < n; i++)
        {
            int data;
            cin >> data;
            if (data != -1 && data != 1)
            {
                xindex = i;
                element=data;
            }

            if (xindex == -1)
            {

                before.push_back(data);
            }
            else
            {

                after.push_back(data);
            }
        }
        
        set<int> left_sums, right_sums;
        computeSubarraySums(before, left_sums);
        computeSubarraySums(after, right_sums);

        set<int> result;
       for(auto i:left_sums)
       {
        result.insert(i);
        result.insert(i+element);
       }  
        for(auto i:right_sums)
       {
        result.insert(i);
        result.insert(i+element);
       }            
        cout << result.size() << "\n";
        for (int s : result) {
            cout << s << " ";
        }
        cout << "\n";

    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
