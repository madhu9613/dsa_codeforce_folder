#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int INF = 1e9;

class SegmentTree
{
    int n;
    vector<pair<int, int>> tree;

public:
    SegmentTree(int sz)
    {
        n = 1;
        while (n < sz)
            n <<= 1;
        tree.assign(2 * n, {INF, -1});
    }

    void update(int idx, pair<int, int> val)
    {
        idx += n;
        tree[idx] = min(tree[idx], val);
        while (idx > 1)
        {
            idx >>= 1;
            tree[idx] = min(tree[2 * idx], tree[2 * idx + 1]);
        }
    }

    pair<int, int> query(int l, int r)
    {
        return query(l, r, 1, 0, n - 1);
    }

private:
    pair<int, int> query(int l, int r, int node, int nl, int nr)
    {
        if (l > r)
            return {INF, -1};
        if (l == nl && r == nr)
            return tree[node];

        int mid = (nl + nr) / 2;
        pair<int, int> res = {INF, -1};

        if (l <= mid)
            res = min(res, query(l, min(r, mid), 2 * node, nl, mid));
        if (r > mid)
            res = min(res, query(max(l, mid + 1), r, 2 * node + 1, mid + 1, nr));

        return res;
    }
};

struct Update
{
    int l, r, idx;
};

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<vector<Update>> updates(n + 1);

    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
            continue;

        int left = max(0, i + 1 - a[i]);
        int right = min(n, i + a[i] - 1);

        updates[i].push_back({left, i, i + 1});
        updates[left].push_back({left, right, i + 1});
    }

    vector<pair<int, int>> dp(n + 1, {INF, -1});
    dp[0] = {0, -1};

    SegmentTree seg(n + 1);
    seg.update(0, {1, -1});

    for (int i = 0; i <= n; i++)
    {
        if (i > 0)
        {
            int pos = min(n, i + a[i - 1] - 1);
            seg.update(pos, {dp[i].first + 1, i});
        }

        for (auto &u : updates[i])
        {
            dp[u.idx] = min(dp[u.idx], seg.query(u.l, u.r));
        }
    }

    if (seg.query(n, n).first == INF)
    {
        cout << -1 << "\n";
        return;
    }

    vector<pair<int, int>> ans;
    int cur = seg.query(n, n).second;

    while (cur != -1)
    {
        ans.push_back({a[cur - 1], cur});
        cur = dp[cur].second;
    }

    sort(ans.begin(), ans.end());

    cout << ans.size() << "\n";
    for (auto &p : ans)
        cout << p.second << " ";
    cout << "\n";
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
