#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t; 
    while (t--) {
        int n;
        cin >> n; 
        vector<int> evens, odds;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            if (x % 2 == 0) {
                evens.push_back(x);
            } else {
                odds.push_back(x);
            }
        }
        
        vector<int> rearranged;
        rearranged.insert(rearranged.end(), evens.begin(), evens.end());
        rearranged.insert(rearranged.end(), odds.begin(), odds.end());
        
        long long s = 0;
        int points = 0;
        for (int num : rearranged) {
            s += num;
            if (s % 2 == 0) {
                ++points;
                while (s % 2 == 0) {
                    s /= 2;
                }
            }
        }
        
        cout << points << endl;
    }
    return 0;
}
