#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = INT_MAX ;

struct node {
    int sum = 0, minPref = 0, maxPref = 0;

    node(int s = 0, int mn = 0, int mx = 0) : sum(s), minPref(mn), maxPref(mx) {}
};

node merge(const node& a, const node& b) {
    return {
        a.sum + b.sum,
        min(a.minPref, a.sum + b.minPref),
        max(a.maxPref, a.sum + b.maxPref)
    };
}

class SegmentTree {
public:
    int n;
    vector<node> tree;

    SegmentTree(int size) : n(size) {
        tree.assign(4 * (n + 1), node(-1, -1, -1));  
    }

    void build(int p, int l, int r) {
        if (l == r) {
            tree[p] = node(-1, -1, -1);
            return;
        }
        int mid = (l + r) / 2;
        build(p * 2, l, mid);
        build(p * 2 + 1, mid + 1, r);
        tree[p] = merge(tree[p * 2], tree[p * 2 + 1]);
    }

    void update(int p, int l, int r, int idx, int val) {
        if (l == r) {
            tree[p].sum += val;
            tree[p].minPref = tree[p].maxPref = tree[p].sum;
            return;
        }
        int mid = (l + r) / 2;
        if (idx <= mid) update(p * 2, l, mid, idx, val);
        else            update(p * 2 + 1, mid + 1, r, idx, val);
        tree[p] = merge(tree[p * 2], tree[p * 2 + 1]);
    }

    node query(int p, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return node(0, INF, -INF);
        if (ql <= l && r <= qr) return tree[p];
        int mid = (l + r) / 2;
        node left = query(p * 2, l, mid, ql, qr);
        node right = query(p * 2 + 1, mid + 1, r, ql, qr);
        return merge(left, right);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<int> a(n + 1);
        int maxVal = 0;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            maxVal = max(maxVal, a[i]);
        }

        vector<vector<int>> val(maxVal + 2);
        for (int i = 1; i <= n; ++i)
            val[a[i]].push_back(i);

        vector<int> low(n + 1, 1), high(n + 1, maxVal);
        vector<int> s(n);
        iota(s.begin(), s.end(), 1);

        vector<vector<int>> bucket(maxVal + 2);
        vector<bool> isMidUsed(maxVal + 2, false);
        vector<int> usedMids;

        SegmentTree seg(n);

        while (!s.empty()) {
            usedMids.clear();

            for (int i : s) {
                if (low[i] < high[i]) {
                    int mid = (low[i] + high[i] + 1) / 2;
                    bucket[mid].push_back(i);
                    if (!isMidUsed[mid]) {
                        isMidUsed[mid] = true;
                        usedMids.push_back(mid);
                    }
                }
            }

            if (usedMids.empty()) break;

            seg.build(1, 1, n);

            int currentValue = maxVal + 1;
            for (int mid = maxVal; mid >= 1; --mid) {
                while (currentValue > mid) {
                    --currentValue;
                    for (int pos : val[currentValue]) {
                        seg.update(1, 1, n, pos, 2); 
                    }
                }

                if (isMidUsed[mid]) {
                    for (int idx : bucket[mid]) {
                        node left = (idx > 1) ? seg.query(1, 1, n, 1, idx - 1) : node(0, 0, 0);
                        node right = seg.query(1, 1, n, idx, n);

                        int prefix = left.sum;
                        int leftMin = min(0, left.minPref);
                        int rightMax = prefix + right.maxPref;

                        if (rightMax >= leftMin)
                            low[idx] = mid;
                        else
                            high[idx] = mid - 1;
                    }
                }
            }

            for (int mid : usedMids) {
                bucket[mid].clear();
                isMidUsed[mid] = false;
            }

            vector<int> ns;
            for (int i : s)
                if (low[i] < high[i])
                    ns.push_back(i);

            s.swap(ns);
        }

        ll answer = 0;
        for (int i = 1; i <= n; ++i)
            answer = max(answer, (ll)low[i] - a[i]);

        cout << answer << '\n';
    }

    return 0;
}
