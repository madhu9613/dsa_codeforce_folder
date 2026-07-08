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

// Fast exponentiation (a^b % mod)
ll modpow(ll a, ll b, ll mod = MOD)
{
    ll res = 1;
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

// GCD
ll gcd(ll a, ll b)
{
    return b ? gcd(b, a % b) : a;
}

// LCM
ll lcm(ll a, ll b)
{
    return a / gcd(a, b) * b;
}

const int MAXN = 3e5 + 5;
int a[MAXN];
vi pos[MAXN];

struct segtree
{
    pair<int, int> tree[4 * MAXN];

    pair<int, int> merge(pair<int, int> a, pair<int, int> b)
    {
        if (a.first == b.first)
            return {a.first, a.second + b.second};

        if (a.second > b.second)
            return {a.first, a.second - b.second};

        return {b.first, b.second - a.second};
    }

    void build(int node, int l, int r)
    {
        if (l == r)
        {
            tree[node] = {a[l], 1};
        }
        else
        {
            int mid = (l + r) / 2;
            build(2 * node, l, mid);
            build(2 * node + 1, mid + 1, r);
            tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
        }
    }

    pair<int, int> query(int node, int l, int r, int ql, int qr)
    {
        if (qr < l || r < ql)
            return {0, 0};

        if (ql <= l && r <= qr)
            return tree[node];

        int mid = (l + r) / 2;
        auto left = query(2 * node, l, mid, ql, qr);
        auto right = query(2 * node + 1, mid + 1, r, ql, qr);

        return merge(left, right);
    }
};
int getfreq(int val, int l, int r)
{
    if (val == 0)
    {
        return 0;
    }
    auto &v = pos[val];
    return upper_bound(v.begin(), v.end(), r) - lower_bound(v.begin(), v.end(), l);
}

void solve()
{
    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        pos[a[i]].push_back(i);
    }

    segtree seg;
    seg.build(1, 1, n);

    while (q--)
    {
        int l, r;
        cin >> l >> r;
        int len = r - l + 1;

        int cand = seg.query(1, 1, n, l, r).first;
        int f = getfreq(cand, l, r);

        int ans = max(1, 2 * f - len);
        cout << ans << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--)
        solve();

    return 0;
}