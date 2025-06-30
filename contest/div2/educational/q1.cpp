/*

QUEATION NO 1
*/
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

long long maxCoins(long long n, unordered_map<long long, long long>& memo) {
    if (n <= 3) return 1; 
    if (memo.find(n) != memo.end()) return memo[n]; 
    
    long long new_value = n / 4;
    memo[n] = 2 * maxCoins(new_value, memo);
    return memo[n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    cin >> t;
    vector<long long> results(t); 

    unordered_map<long long, long long> memo; 

    for (int i = 0; i < t; ++i) {
        long long n;
        cin >> n;
        results[i] = maxCoins(n, memo); 
    }

    for (const auto& res : results) {
        cout << res << "\n"; 
    }

    return 0;
}
