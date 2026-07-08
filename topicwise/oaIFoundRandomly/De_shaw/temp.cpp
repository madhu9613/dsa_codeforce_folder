#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 100005;
vector<int> adj[MAXN];
int tin[MAXN], tout[MAXN], timer;
int parent[MAXN];

// Standard DSU find with path compression
int find(int i)
{
    if (parent[i] == i)
        return i;
    return parent[i] = find(parent[i]);
}

// Standard DSU unite
void unite(int x, int y)
{
    int rootX = find(x);
    int rootY = find(y);
    if (rootX != rootY)
    {
        parent[rootX] = rootY;
    }
}

// DFS to establish final hierarchy for O(1) ancestor checks
void dfs(int u)
{
    tin[u] = ++timer;
    for (int v : adj[u])
        dfs(v);
    tout[u] = ++timer;
}

// Ancestor check using entry/exit times
bool is_ancestor(int u, int v)
{
    return tin[u] <= tin[v] && tout[v] <= tout[u];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    struct Event
    {
        int type, x, y;
    };
    vector<Event> events(m);
    vector<int> boss(n + 1, 0);

    // Initialize DSU parents
    for (int i = 1; i <= n; i++)
        parent[i] = i;

    // First pass: Read events to build the final tree structure
    for (int i = 0; i < m; i++)
    {
        cin >> events[i].type;
        if (events[i].type == 1)
        {
            cin >> events[i].x >> events[i].y;
            adj[events[i].y].push_back(events[i].x);
            boss[events[i].x] = events[i].y;
        }
        else if (events[i].type == 2)
        {
            cin >> events[i].x;
        }
        else
        {
            cin >> events[i].x >> events[i].y;
        }
    }

    // Pre-calculate hierarchical times using DFS
    for (int i = 1; i <= n; i++)
    {
        if (boss[i] == 0)
            dfs(i);
    }

    // Second pass: Process events chronologically with DSU
    vector<int> packet_owner(m + 1);
    int packet_cnt = 0;

    for (int i = 0; i < m; i++)
    {
        if (events[i].type == 1)
        {
            // Employee x gets a boss y; link them in the DSU
            unite(events[i].x, events[i].y);
        }
        else if (events[i].type == 2)
        {
            packet_owner[++packet_cnt] = events[i].x;
        }
        else
        {
            int x = events[i].x;
            int owner = packet_owner[events[i].y];

            // Check:
            // 1. Is x an ancestor of owner in the final structure?
            // 2. Were they in the same component at the time of the query?
            if (is_ancestor(x, owner) && find(x) == find(owner))
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
        }
    }
    return 0;
}