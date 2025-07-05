#include<bits/stdc++.h>
using namespace std;

int fun(int n, int MOD) {
    vector<int> dp(n + 1, 0);
    dp[0] = 1 % MOD;
    int maxk = 0;

    for (int i = n; i>= 1; --i) {
        for (int j = maxk; j >= 0; --j) {
            if (dp[j] == 0) continue;
            int f = n - i + 1 - j;
            if (f <= 0) break;

            long long add = (1LL * dp[j] * f) % MOD;
            add = (add * i) % MOD;

            dp[j + 1] = (dp[j + 1] + add) % MOD;
        }
        if (dp[maxk + 1]) maxk++;
    }

    int res = 0;
    for (int val : dp) {
        res = (res + val) % MOD;
    }
    return res;
}

int main() {
    int t;
    cin>>t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        cout << fun(n, m) << '\n';
    }
    return 0;
}