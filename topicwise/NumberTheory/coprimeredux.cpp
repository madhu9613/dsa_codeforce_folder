#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 5;

int power(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

int freq[MAX];     
int countDiv[MAX];
int f[MAX];        
int cnt[MAX];      

int32_t main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        freq[a[i]]++;
    }

    for (int i = 1; i <= m; ++i) {
        for (int j = i; j <= m; j += i) {
            countDiv[i] += freq[j];
        }
    }

    for (int i = 1; i <= m; ++i) {
        if (countDiv[i] > 0)
            f[i] = (power(2, countDiv[i]) - 1 + MOD) % MOD;
    }

    for (int i = m; i >= 1; --i) {
        cnt[i] = f[i];
        for (int j = 2 * i; j <= m; j += i) {
            cnt[i] = (cnt[i] - cnt[j] + MOD) % MOD;
        }
    }

    for (int i = 1; i <= m; ++i)
        cout << cnt[i] << " ";
    cout << '\n';
    
    return 0;
}
