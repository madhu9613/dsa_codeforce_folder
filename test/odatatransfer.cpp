#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Function to check if a number is prime
bool isprime(int n) {
    if (n <= 1)
        return false;
    if (n == 2 || n == 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

void solve() {
    int t;
    cin >> t;
    
    }


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
