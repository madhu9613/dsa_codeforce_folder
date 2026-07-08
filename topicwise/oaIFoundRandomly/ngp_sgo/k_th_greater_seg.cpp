
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

struct segtree
{
    int n;
    vi seg;

    segtree(int n = 0)
    {
        this->n = n;
        seg.assign(4 * n + 5, 0);
    }

    void update(int node, int l, int r, int idx)
    {
        if (l == r)
        {
            seg[node] = 1;
            return;
        }

        int mid = (l + r) / 2;

        if (idx <= mid)
            update(2 * node, l, mid, idx);
        else
            update(2 * node + 1, mid + 1, r, idx);

        seg[node] = seg[2 * node] + seg[2 * node + 1];
    }

    void update(int idx)
    {
        update(1, 1, n, idx);
    }

    int query(int node, int l, int r, int ql, int qr)
    {
        if (qr < l || r < ql)
            return 0;

        if (ql <= l && r <= qr)
            return seg[node];

        int mid = (l + r) / 2;

        return query(2 * node, l, mid, ql, qr) + query(2 * node + 1, mid + 1, r, ql, qr);
    }

    int query(int l, int r)
    {
        if (l > r)
            return 0;

        return query(1, 1, n, l, r);
    }

    // returns position of k-th active index
    int kth(int node, int l, int r, int k)
    {
        if (l == r)
            return l;

        int leftcnt = seg[2 * node];
        int mid = (l + r) / 2;

        if (leftcnt >= k)
            return kth(2 * node, l, mid, k);

        return kth(2 * node + 1, mid + 1, r,
                   k - leftcnt);
    }

    int kth(int k)
    {
        return kth(1, 1, n, k);
    }
};

void solve()
{

    int n, k;
    cin >> n >> k;

    vi nums(n);

    for (int i = 0; i < n; i++)
        cin >> nums[i];

    vi ans(n, -1);

    vector<pair<int, int>> v;

    for (int i = 0; i < n; i++)
    {
        v.push_back({nums[i], i});
    }

    sort(all(v), [](auto &a, auto &b)
         { return a.first > b.first; });

    segtree st(n);

    int i = 0;

    while (i < n)
    {

        int j = i;

        // group equal values
        while (j < n &&
               v[j].first == v[i].first)
            j++;

        // QUERY PHASE
        for (int p = i; p < j; p++)
        {

            int idx = v[p].second;

            // count active positions strictly to the right
            int greaterRight =
                st.query(idx + 2, n);

            if (greaterRight < k)
            {
                ans[idx] = -1;
                continue;
            }

            // active positions before current index
            int before =
                st.query(1, idx);

            int target = before + k;

            int pos = st.kth(target);

            ans[idx] = nums[pos - 1];
        }

        // INSERT PHASE
        for (int p = i; p < j; p++)
        {
            st.update(v[p].second + 1);
        }

        i = j;
    }

    for (int x : ans)
        cout << x << " ";
    cout << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while (t--)
        solve();

    return 0;
}

