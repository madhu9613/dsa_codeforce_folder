#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// Precomputed derangements for k = 0 to 4
ll derangement[5] = {1, 0, 1, 2, 9};

// Safe computation of C(n, r)
ll combination(int n, int r) {
    if (r > n) return 0;
    ll res = 1;
    for (int i = 1; i <= r; ++i) {
        res *= (n - i + 1);
        res /= i;
    }
    return res;
}

int main() {
    int n, k;
    cin >> n >> k;

    ll result = 0;
    for (int i = 0; i <= k; ++i) {
        ll comb = combination(n, i);
        result += comb * derangement[i];
    }

    cout << result << endl;
    return 0;
}
