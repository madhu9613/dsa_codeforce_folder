#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solve(vector<long long> v, int n) {
    if (n == 1) {
        return 1; 
    }

    vector<long long> distances;

    for (int i = 1; i < n; ++i) {
        distances.push_back(v[i] - v[i - 1]);
    }

    int M = *max_element(distances.begin(), distances.end());
    int m = *min_element(distances.begin(), distances.end());

    if (n % 2 == 0) {
        return M;
    } else {
        long long left = m, right = M;
        int ans = M; 

        while (left < right) {
            long long mid = left + (right - left) / 2;
            int count = 0;

            for (int i = 0; i < distances.size(); i++) {
                if (distances[i] > mid) {
                    count++;
                }
            }

            if (count <= 1) {
                ans = mid; // Update answer to current mid
                right = mid; // Try smaller k
            } else {
                left = mid + 1; // Increase k
            }
        }
        return ans; // Return the found minimum k
    }
}

int main() {
    int t;
    cin >> t; 
    while (t--) {
        int n;
        cin >> n; 
        vector<long long> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i]; 
        }
        int ans = solve(v, n); // Solve for current test case
        cout << ans << endl; // Output the result
    }

    return 0;
}
