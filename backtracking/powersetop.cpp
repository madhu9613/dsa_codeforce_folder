#include <bits/stdc++.h>
using namespace std;

// Recursive function to generate the power set
void solve(const vector<int>& nums, vector<int>& current, vector<vector<int>>& result, int index) {
    // Base case: if index reaches the end, add the current subset to result
    if (index >= nums.size()) {
        result.push_back(current);
        return;
    }
                                                                                                               
    current.push_back(nums[index]);
    solve(nums, current, result, index + 1);

    current.pop_back();

    // // Skip duplicates
    while (index + 1 < nums.size() && nums[index] == nums[index + 1]) {
        index++;
    }

    solve(nums, current, result, index + 1);
}

// Function to generate the power set
vector<vector<int>> generatepowerset(vector<int> nums) {
    vector<vector<int>> ans;
    vector<int> current;

    // Sort the numbers to handle duplicates
    sort(nums.begin(), nums.end());

    // Start the recursive process
    
    solve(nums, current, ans, 0);
    sort(ans.begin(),ans.end());

    return ans;
}

int main() {
    vector<int> nums;
    string input;

    // Input handling
    cout << "Enter numbers separated by spaces: ";
    getline(cin, input);
    stringstream ss(input);
    int data;
    while (ss >> data) {
        nums.push_back(data);
    }

    // Generate the power set
    vector<vector<int>> result = generatepowerset(nums);

    // Print the power set
    cout << "Power set:" << endl;
    for (const auto& subset : result) {
        cout << "{ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "}" << endl;
    }

    return 0;
}
