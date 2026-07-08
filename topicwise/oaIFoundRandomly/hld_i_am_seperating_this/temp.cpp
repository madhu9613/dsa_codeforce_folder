#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 200005;

int n, q;
vector<int> adj[MAXN];
int vals[MAXN];

int par[MAXN], depth[MAXN], heavy[MAXN], head[MAXN], pos[MAXN];
int cpos = 1;
int flat[MAXN];

struct segtree {
    int n;
    vector<int> tree;
    
    segtree() {} 
    
    segtree(int n) {
        this->n = n;
        tree.resize(4 * n + 5);
        build(1, 1, n);
    }
    
    void build(int node, int l, int r) {
        if (l == r) {
            tree[node] = flat[l];
            return;
        }
        int mid = l + (r - l) / 2;
        build(2 * node, l, mid);
        build(2 * node + 1, mid + 1, r);
        tree[node] = max(tree[2 * node], tree[2 * node + 1]);
    }
    
    void update(int node, int l, int r, int idx, int val) {
        if (l == r) {
            tree[node] = val;
            return;
        }
        int mid = l + (r - l) / 2;
        if (idx <= mid) {
            update(2 * node, l, mid, idx, val);
        } else {
            update(2 * node + 1, mid + 1, r, idx, val);
        }
        tree[node] = max(tree[2 * node], tree[2 * node + 1]);
    }

    int query(int node, int l, int r, int ql, int qr) {
        if (ql > r || qr < l) {
            return 0;
        }
        if (ql <= l && qr >= r) {
            return tree[node];
        }
        int mid = l + (r - l) / 2;
        return max(query(2 * node, l, mid, ql, qr), query(2 * node + 1, mid + 1, r, ql, qr));
    }

    void update(int idx, int val) {
        update(1, 1, n, idx, val);
    }
    
    int query(int l, int r) {
        return query(1, 1, n, l, r);
    }
};

segtree st;

int dfs1(int u, int p) {
    int sz = 1;
    int max_child = 0;
    heavy[u] = -1; // no heavy child yet
    
    for (int v : adj[u]) {
        if (v == p) continue;

        par[v] = u;
        depth[v] = depth[u] + 1;
        int child = dfs1(v, u);
        sz += child;
        if (child > max_child) {
            max_child = child;
            heavy[u] = v;
        }
    }
    return sz;
}

void decompose(int u, int p, int h) {
    head[u] = h;
    pos[u] = cpos++;
    flat[pos[u]] = vals[u]; // FIX 2: Populate the flat array!
    
    if (heavy[u] != -1) {
        decompose(heavy[u], u, h);
    }

    for (int v : adj[u]) {
        // FIX 1: Must NOT be parent AND MUST NOT be the heavy child
        if (v != p && v != heavy[u]) { 
            decompose(v, u, v);
        }
    }
}

int path_query(int a, int b) {
    int res = 0;
    while (head[a] != head[b]) {
        if (depth[head[a]] < depth[head[b]]) {
            swap(a, b);
        }
        res = max(res, st.query(pos[head[a]], pos[a]));
        a = par[head[a]];
    }
    if (depth[a] > depth[b]) {
        swap(a, b);
    }
    res = max(res, st.query(pos[a], pos[b]));
    return res;
}

void solve() {
    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        cin >> vals[i];
    }

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    depth[1] = 0;
    par[1] = 0;
    
    dfs1(1, 0);
    decompose(1, 0, 1);
    
    // FIX 3b: Build the segment tree AFTER decompose populates the flat array
    st = segtree(n); 

    for (int i = 0; i < q; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            int s, x;
            cin >> s >> x;
            vals[s] = x;
            st.update(pos[s], x);
        } else if (t == 2) {
            int a, b;
            cin >> a >> b;
            cout << path_query(a, b) << " ";
        }
    }
    cout << "\n";
}

int main() {
    // Adding fast I/O is highly recommended for CP
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}