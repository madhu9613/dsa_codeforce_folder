#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> &base, vector<int> &newbase) {
    return (newbase[0] <= base[0] && newbase[1] <= base[1] && newbase[2] <= base[2]);
}

 int lengthOfLIS(vector<vector<int>> &nums) {
        int n = nums.size();
        // vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0)); 
        vector<int> nextrow(n+1,0);
        vector<int> currrow(n+1,0);
        
    
        for (int curr = n - 1; curr >= 0; curr--) {
            for (int prev = curr - 1; prev >= -1; prev--) {
                int include = 0;
                if (prev == -1 || check(nums[curr],nums[prev])) {
                    include = nums[curr][2] + nextrow[curr + 1]; 
                }
                int exclude = nextrow[prev + 1];

                currrow[prev + 1] = max(include, exclude);
            }
            nextrow=currrow;
        }

        return nextrow[0]; // LIS starting from index 0
    }


int solve(vector<vector<int>> &cuboids) {
    for (auto &cube : cuboids) {
        sort(cube.begin(), cube.end());
    }

    sort(cuboids.begin(), cuboids.end());

    return lengthOfLIS(cuboids);
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> cuboids(n, vector<int>(3));
    
    for (int i = 0; i < n; i++) {
        cin >> cuboids[i][0] >> cuboids[i][1] >> cuboids[i][2];
    }

    cout << solve(cuboids) << endl;  
    return 0;
}
