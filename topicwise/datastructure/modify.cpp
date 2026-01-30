#include <bits/stdc++.h>
using namespace std;

static const int MOD = 1e9 + 7;

/* Fenwick Tree (1-indexed) */
struct Fenwick
{
    int n;
    vector<long long> bit;
    Fenwick(int n) : n(n), bit(n + 1, 0) {}

    void add(int i, long long v)
    {
        for (; i <= n; i += i & -i)
        {
            bit[i] = (bit[i] + v) % MOD;
        }
    }

    long long sum(int i)
    {
        long long s = 0;
        for (; i > 0; i -= i & -i)
        {
            s = (s + bit[i]) % MOD;
        }
        return s;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> a(n);
    for (auto &x : a)
        cin >> x;

    /* ---- keep only distinct values ---- */
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    int m = a.size();

    /* Maximum possible length = m */
    int maxLen = m;

    /* Fenwick tree for each length */
    vector<Fenwick> fenw;
    for (int i = 0; i <= maxLen; i++)
    {
        fenw.emplace_back(m);
    }

    /* dp[len] temporary storage for current value */
    vector<long long> dp(maxLen + 1, 0);

    /* process values in increasing order */
    for (int v = 1; v <= m; v++)
    {
        dp[1] = 1; // subsequence [value]

        for (int len = 2; len <= maxLen; len++)
        {
            dp[len] = fenw[len - 1].sum(v - 1);
        }

        for (int len = 1; len <= maxLen; len++)
        {
            if (dp[len] > 0)
                fenw[len].add(v, dp[len]);
        }
    }

    /* output answer per length */
    for (int len = 1; len <= maxLen; len++)
    {
        long long ans = fenw[len].sum(m);
        if (ans == 0)
            break;
        cout << "length " << len << " : " << ans << "\n";
    }

    return 0;
}
