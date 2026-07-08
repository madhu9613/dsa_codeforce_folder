#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define vi vector<int>
#define vll vector<ll>
#define vpi vector<pii>
#define vpll vector<pll>

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

const ll INF = 1e18;
const int MOD = 1000000007;
const int MAXN = 2e5 + 5;

ll modpow(ll a, ll b, ll mod = MOD)
{
    ll res = 1;
    a %= mod;
    while (b)
    {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

ll modinv(ll a, ll mod = MOD)
{
    return modpow(a, mod - 2, mod);
}

ll gcd(ll a, ll b)
{
    return b ? gcd(b, a % b) : a;
}

ll lcm(ll a, ll b)
{
    return a / gcd(a, b) * b;
}

int B = 330;

void solve()
{
    int n, m, q;
    cin >> n >> m >> q;

    vll a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    vector<vector<int>> S(m + 1);
    vi heavy_idx;
    vi is_heavy(m + 1, -1);
    for (int i = 1; i <= m; i++)
    {
        int sz;
        cin >> sz;
        S[i].resize(sz);
        for (int j = 0; j < sz; j++)
        {
            cin >> S[i][j];
        }
        if (sz >= B)
        {
            is_heavy[i] = heavy_idx.size();
            heavy_idx.push_back(i);
        }
    }
    int nums_heavy = heavy_idx.size();
    vll heavy_sum(nums_heavy, 0);
    vll heavy_add(nums_heavy, 0);
    vector<vi> overlap(m + 1, vi(nums_heavy, 0));
    vector<bool> in_heavy(n + 1, false);
    for (int j = 0; j < nums_heavy; j++)
    {
        int h_id = heavy_idx[j];
        for (int idx : S[h_id])
        {
            in_heavy[idx] = true;
            heavy_sum[j] += a[idx];
        }
        for (int i = 1; i <= m; i++)
        {
            for (int idx : S[i])
            {
                if (in_heavy[idx])
                {
                    overlap[i][j]++;
                }
            }
        }

        for (int idx : S[h_id])
        {
            in_heavy[idx] = false;
        }
    }

    while (q--)
    {
        char t;
        cin >> t;
        if (t == '+')
        {
            int k;
            ll x;
            cin >> k >> x;
            if (is_heavy[k] != -1)
            {
                heavy_add[is_heavy[k]] += x;
            }
            else
            {
                for (int idx : S[k])
                {
                    a[idx] += x;
                }
                for (int j = 0; j < nums_heavy; j++)
                {
                    heavy_sum[j] += x * overlap[k][j];
                }
            }
        }
        else
        {
            int k;
            cin >> k;
            ll ans = 0;
            if (is_heavy[k] != -1)
            {
                ans = heavy_sum[is_heavy[k]];
            }
            else
            {
                for (int idx : S[k])
                {
                    ans += a[idx];
                }
            }

            for (int j = 0; j < nums_heavy; j++)
            {
                ans += heavy_add[j] * overlap[k][j];
            }
            cout << ans << endl;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // precompute();
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t = 1;
    while (t--)
        solve();
    return 0;
}