#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long x, y, k;
        cin >> x >> y >> k;

        long long moves_x = (x + k - 1) / k; 
        long long moves_y = (y + k - 1) / k; 

        long long max_moves = max(moves_x, moves_y);
        
        long long total_moves = 2 * max_moves-(moves_x>moves_y);
cout<<total_moves<<endl;
        
    }
    return 0;
}
