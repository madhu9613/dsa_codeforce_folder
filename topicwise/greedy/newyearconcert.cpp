#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define max3(a, b, c) max(max(a, b), c)
#define max4(a, b, c, d) max(max(a, b), max(c, d))
#define pii pair<int, int>
#define pll pair<ll, ll>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl '\n'

ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
const int MOD = 1e9 + 7;
const int INF = INT_MAX;
const ll LINF = 1e18;

struct SegmentTree
{
    int size;
    vector<ll> tree;

    void init(int n)
    {
        size = 1;
        while (size < n)
            size <<= 1;
        tree.assign(2 * size, 0LL);
    }

    void build(const vector<ll> &a, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            if (lx < (int)a.size())
                tree[x] = a[lx];
            return;
        }
        int m = (lx + rx) / 2;
        build(a, 2 * x + 1, lx, m);
        build(a, 2 * x + 2, m, rx);
        tree[x] = gcd(tree[2 * x + 1], tree[2 * x + 2]);
    }

    void build(const vector<ll> &a)
    {
        build(a, 0, 0, size);
    }

    void set(int i, ll v, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            tree[x] = v;
            return;
        }
        int m = (lx + rx) / 2;
        if (i < m)
            set(i, v, 2 * x + 1, lx, m);
        else
            set(i, v, 2 * x + 2, m, rx);
        tree[x] = gcd(tree[2 * x + 1], tree[2 * x + 2]);
    }

    void set(int i, ll v)
    {
        set(i, v, 0, 0, size);
    }

    ll query(int l, int r, int x, int lx, int rx)
    {
        if (lx >= r || l >= rx)
            return 0;
        if (lx >= l && rx <= r)
            return tree[x];
        int m = (lx + rx) / 2;
        ll s1 = query(l, r, 2 * x + 1, lx, m);
        ll s2 = query(l, r, 2 * x + 2, m, rx);
        return gcd(s1, s2);
    }

    ll query(int l, int r)
    {
        return query(l, r, 0, 0, size);
    }
};
void solve()
{
    int n;
    cin >> n;
    vll a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    SegmentTree st;
    st.init(n);
    st.build(a);

    vector<pair<int, int>> bad;
    for (int l = 0; l < n; l++)
    {
        int low = l, high = n - 1, best = l - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            ll g = st.query(l, mid + 1);
            if (g >= mid - l + 1)
            {
                best = mid;
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        if (best >= l)
        {
            ll g = st.query(l, best + 1);
            if (g == best - l + 1)
                bad.push_back({l, best});
        }
    }

    vector<int> ans(n);
    int changes = 0, lastCovered = -1, idx = 0;
    sort(bad.begin(), bad.end(), [](auto &x, auto &y)
         { return x.second < y.second; });
    for (int i = 0; i < n; i++)
    {
        while (idx < (int)bad.size() && bad[idx].second == i)
        {
            if (bad[idx].first > lastCovered)
            {
                changes++;
                lastCovered = i;
            }
            idx++;
        }
        ans[i] = changes;
    }

    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    while (t--)
        solve();
    return 0;
}