#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

#define ll long long
#define pb push_back
#define vi vector<int>

vector<int> parentVec, rnk; // renamed rank → rnk

// -------------------- DSU --------------------
void make_set(int n)
{
    parentVec.resize(n);
    rnk.assign(n, 0);
    for (int i = 0; i < n; i++)
        parentVec[i] = i;
}

int find_par(int x)
{
    if (parentVec[x] != x)
        parentVec[x] = find_par(parentVec[x]);
    return parentVec[x];
}

void unite(int a, int b)
{
    a = find_par(a);
    b = find_par(b);
    if (a != b)
    {
        if (rnk[a] < rnk[b])
            swap(a, b);
        parentVec[b] = a;
        if (rnk[a] == rnk[b])
            rnk[a]++;
    }
}

// -------------------- KRUSKAL --------------------
int kruskal(int n, vector<vector<int>> &edges)
{
    sort(edges.begin(), edges.end(),
         [](auto &a, auto &b)
         {
             return a[2] < b[2];
         });

    make_set(n);

    int mst_cost = 0, edges_used = 0;

    for (auto &e : edges)
    {
        int u = e[0], v = e[1], w = e[2];
        if (find_par(u) != find_par(v))
        {
            unite(u, v);
            mst_cost += w;
            edges_used++;
            if (edges_used == n - 1)
                break;
        }
    }
    return mst_cost;
}

// -------------------- PRIM --------------------
int prims(int n, vector<vector<pair<int, int>>> &adj)
{
    vector<bool> in_mst(n, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, 0});
    int mst_cost = 0;

    while (!pq.empty())
    {
        auto [w, node] = pq.top();
        pq.pop();

        if (in_mst[node])
            continue;

        in_mst[node] = true;
        mst_cost += w;

        for (auto &p : adj[node])
        {
            int nxt = p.first;
            int wt = p.second;
            if (!in_mst[nxt])
                pq.push({wt, nxt});
        }
    }
    return mst_cost;
}

// -------------------- MAIN SOLVE --------------------
void solve()
{
    int n, m;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    vector<vector<int>> edges;
    vector<vector<pair<int, int>>> adj(n);

    cout << "Enter edges: u v w\n";
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    // ---- Kruskal Time ----
    auto start1 = high_resolution_clock::now();
    int kr = kruskal(n, edges);
    auto stop1 = high_resolution_clock::now();
    auto duration1 = duration_cast<microseconds>(stop1 - start1);

    // ---- Prim Time ----
    auto start2 = high_resolution_clock::now();
    int pr = prims(n, adj);
    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<microseconds>(stop2 - start2);

    cout << "\n===== RESULTS =====\n";
    cout << "Kruskal MST Cost = " << kr << "\n";
    cout << "Kruskal Time: " << duration1.count() << " microseconds\n\n";

    cout << "Prim MST Cost = " << pr << "\n";
    cout << "Prim Time: " << duration2.count() << " microseconds\n";
}

int main()
{
    int t = 1;
    while (t--)
        solve();
    return 0;
}
