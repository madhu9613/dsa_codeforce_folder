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

struct DSU
{
    vi parent, rank;
    DSU(int n)
    {
        parent.resize(n + 1);
        rank.assign(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            parent[i] = i;
        }
    }
    int find(int x)
    {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }
    void unite(int a, int b)
    {
        a = find(a);
        b = find(b);
        if (a == b)
            return;
        if (rank[a] <= rank[b])
            swap(a, b);
        parent[b] = a;
        if (rank[a] == rank[b])
            rank[a]++;
    }
};
void solve()
{
    freopen("wormsort.in", "r", stdin);
    freopen("wormsort.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    vi p(n + 1);
    bool sorted = true;
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
        if (p[i] != i)
            sorted = false;
    }

    if (sorted)
    {
        cout << -1 << endl;
        return;
    }

    struct Edge
    {
        int a, b, w;
    };
    vector<Edge> edges(m);
    int maxw = 0;
    for (int i = 0; i < m; i++)
    {
        cin >> edges[i].a >> edges[i].b >> edges[i].w;
        maxw = max(maxw, edges[i].w);
    }
    auto cansort = [&](int m)
    {
        DSU dsu(n);
        for (auto &e : edges)
        {
            if (e.w >= m)
                dsu.unite(e.a, e.b);
        }
        for (int i = 1; i <= n; i++)
        {
            if (dsu.find(i) != dsu.find(p[i]))
                return false;
        }
        return true;
    };

    int l=1,r=maxw,ans=1;
    while (l<=r)
    {
        int m=l+(r-l)/2;
        if(cansort(m))
        {
            ans=m;
            l=m+1;
        }else{
            r=m-1;
        }
    }

    cout<<ans<<endl;

    
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