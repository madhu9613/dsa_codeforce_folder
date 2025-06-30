#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minFlipsForGroup(vector<char>& group) {
    int count_0 = count(group.begin(), group.end(), '0');
    int count_1 = group.size() - count_0; // The rest are 1s
    return min(count_0, count_1);
}

void solve() {
    int t;
    cin >> t; 
    
    while (t--) {
        int n;
        cin >> n; 
        vector<string> grid(n);
        
        for (int i = 0; i < n; i++) {
            cin >> grid[i];
        }
        
        int min_operations = 0;
        
        for (int i = 0; i < n / 2; i++) {
            for (int j = 0; j < n / 2; j++) {
                vector<char> group = {
                    grid[i][j],              // (i, j)
                    grid[j][n - 1 - i],      // (j, n-1-i)
                    grid[n - 1 - i][n - 1 - j],  // (n-1-i, n-1-j)
                    grid[n - 1 - j][i]       // (n-1-j, i)
                };
                
                min_operations += minFlipsForGroup(group);
            }
        }
        
        if (n % 2 == 1) {
        }
        
        cout << min_operations << endl;
    }
}

int main() {
    solve();  
    return 0;
}
