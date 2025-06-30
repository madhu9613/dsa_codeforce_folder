/*

QUEATION NO 2
*/
#include <iostream>
#include <algorithm>
using namespace std;

void solve() {
    int t;
    cin >> t;  
    while (t--) {
        int a1, a2, a4, a5;
        cin >> a1 >> a2 >> a4 >> a5;  
        
        int x1 = a1 + a2; 
        int x2 = a4 - a2;  
        int x3 = a5 - a4;  
        
        int max_fib = 0;
        
        for (int a3 : {x1, x2, x3}) {
            int fib_count = 0;
            
            if (a3 == a1 + a2) {
                fib_count++;
            }
            if (a4 == a2 + a3) {
                fib_count++;
            }
            if (a5 == a3 + a4) {
                fib_count++;
            }
            
            max_fib = max(max_fib, fib_count);
        }
        
        cout << max_fib << endl;
    }
}

int main() {
    solve();
    return 0;
}
