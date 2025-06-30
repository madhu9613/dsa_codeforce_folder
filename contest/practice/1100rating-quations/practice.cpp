/*
print the pair with smallest difference....
*/
#include <bits/stdc++.h>
using namespace std;

pair<int, int> solve(vector<int> nums)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());
    pair<int,int> ans;
    int mini = INT_MAX;
    for (int i = 0; i < n - 1; i++)
    {
        if (abs(nums[i] - nums[i + 1]) < mini)
        {
            mini = abs(nums[i] - nums[i + 1]);
            ans.first=nums[i];
            ans.second=nums[i+1];
        }
    }
return ans;    
}
int main()
{
    int n;
    cin >> n;
    vector<int> nums;
    for (int i = 0; i < n; i++)
    {
        int data;
        cin>>data;
        nums.push_back(data);
    }
pair<int,int> result=solve(nums);
cout<<"pair is :"<<result.first<<" "<<result.first+1<<endl;
    return 0;
}