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
        cin >> n;
        vector<int> before, after;
        int xindex = -1;
        int element;
        
        // Read the array and split into before and after arrays
        for (int i = 0; i < n; i++)
        {
            int data;
            cin >> data;
            
            if (data != 1 && data != -1) // Correct condition to find the special element
            {
                xindex = i;
                element = data;
                continue;
            }
            
            if (xindex == -1) {
                before.push_back(data); // Add to before array if no special element found yet
            } else {
                after.push_back(data);  // Add to after array once special element is found
            }
        }
        
        // Compute subarray sums for the two parts
        set<int> left_sums, right_sums;
        computeSubarraySums(before, left_sums);
        computeSubarraySums(after, right_sums);

        set<int> result;
        
        // Add sums from left part
        for (auto i : left_sums) {
            result.insert(i);
            result.insert(i + element); // Add element to the sum
        }
        
        // Add sums from right part
        for (auto i : right_sums) {
            result.insert(i);
            result.insert(i + element); // Add element to the sum
        }
        
        // Output the result
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
