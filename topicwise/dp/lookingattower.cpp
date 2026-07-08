#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define vll vector<ll>
#define vi vector<int>
#define all(x) (x).begin(), (x).end()

const ll MOD = 998244353;

/* Fast power */
ll modpow(ll a, ll b)
{
    ll res = 1;
    while (b)
    {
        if (b & 1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

void solve()
{
    int n;
    cin >> n;

    vll a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    /* Precompute powers of 2 */
    vll pow2(n + 1), inv2(n + 1);
    pow2[0] = 1;
    for (int i = 1; i <= n; i++)
        pow2[i] = (pow2[i - 1] * 2) % MOD;

    for (int i = 0; i <= n; i++)
        inv2[i] = modpow(pow2[i], MOD - 2);

    /* Compute L(a) */
    vll pref;
    ll mx = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > mx)
            pref.push_back(a[i]);
        mx = max(mx, a[i]);
    }

    /* Compute R(a) */
    vll suf;
    mx = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i] > mx)
            suf.push_back(a[i]);
        mx = max(mx, a[i]);
    }

    int k1 = pref.size();
    int k2 = suf.size();

    vll dpL(n, 0), sumL(k1, 0);
    vll dpR(n, 0), sumR(k2, 0);

    /* -------- LEFT DP -------- */
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k1; j++)
        {
            if (a[i] == pref[j])
            {
                if (j == 0)
                {
                    dpL[i] = 1;
                }
                else
                {
                    int cnt = 0;
                    for (int x = 0; x < i; x++)
                        if (a[x] <= pref[j - 1])
                            cnt++;

                    dpL[i] = (pow2[cnt] * sumL[j - 1]) % MOD;
                }

                int cnt2 = 0;
                for (int x = 0; x <= i; x++)
                    if (a[x] <= pref[j])
                        cnt2++;

                sumL[j] = (sumL[j] + dpL[i] * inv2[cnt2]) % MOD;
            }
        }
    }

    /* -------- RIGHT DP -------- */
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < k2; j++)
        {
            if (a[i] == suf[j])
            {
                if (j == 0)
                {
                    dpR[i] = 1;
                }
                else
                {
                    int cnt = 0;
                    for (int x = i + 1; x < n; x++)
                        if (a[x] <= suf[j - 1])
                            cnt++;

                    dpR[i] = (pow2[cnt] * sumR[j - 1]) % MOD;
                }

                int cnt2 = 0;
                for (int x = i; x < n; x++)
                    if (a[x] <= suf[j])
                        cnt2++;

                sumR[j] = (sumR[j] + dpR[i] * inv2[cnt2]) % MOD;
            }
        }
    }

    /* -------- FINAL ANSWER -------- */
    ll ans = 0;
    ll maxVal = pref.back();

    for (int i = 0; i < n; i++)
    {
        if (a[i] == maxVal)
        {
            for (int j = i; j < n; j++)
            {
                if (a[j] == maxVal)
                {
                    ll middle = pow2[max(0, j - i - 1)];
                    ans = (ans + dpL[i] * dpR[j] % MOD * middle) % MOD;
                }
            }
        }
    }

    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
