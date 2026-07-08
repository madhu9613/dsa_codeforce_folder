#include <bits/stdc++.h>

using namespace std;

const int N = 55;
const int MOD = 998244353;

int mul(int x, int y)
{
    return x * 1LL * y % MOD;
}

int binpow(int x, int y)
{
    int z = 1;
    while (y > 0)
    {
        if (y & 1)
            z = mul(z, x);
        x = mul(x, x);
        y >>= 1;
    }
    return z;
}

int main()
{
    vector<int> f(N, 1);
    for (int i = 1; i < N; ++i)
        f[i] = (f[i - 1] * 1LL * i) % MOD;

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        for (int &x : a)
            cin >> x;
        int k = accumulate(a.begin(), a.end(), 0) / n;
        int z = 0, bad = 0;
        for (int i = 1; i <= n; ++i)
        {
            int x = min(a[i], k);
            a[i] -= x;
            a[0] -= k - x;
            z += a[i] == 0;
            bad |= a[i] > 1 || a[0] < 0;
        }
        bad |= a[0] > z;
        int ans = bad ? 0 : f[z];
        if (!bad)
        {
            ans = mul(ans, f[n - z + a[0]]);
            ans = mul(ans, binpow(f[a[0]], MOD - 2));
        }
        cout << ans << '\n';
    }
}