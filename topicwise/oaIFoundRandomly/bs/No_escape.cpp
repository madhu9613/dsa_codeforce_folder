#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
#define vi vector<int>
#define vll vector<ll>
#define vpi vector<pii>
#define vpll vector<pll>

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

const ll INF = 1e18;
const int MOD = 1000000007;
const int MAXN = 2e5 + 5;

ll modpow(ll a, ll b, ll mod = MOD) {
    ll res = 1;
    a %= mod;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

ll modinv(ll a, ll mod = MOD) {
    return modpow(a, mod - 2, mod);
}

ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

struct edge{
    int to;
    ll w;
};
struct node{
int r,c,id;
};

struct ladder{
int r1,c1,r2,c2,h;
};

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vll x(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> x[i];

    vector<pii> pts;
    pts.push_back({1, 1});
    pts.push_back({n, m});

    struct Ladder
    {
        int r1, c1, r2, c2, h;
    };
    vector<Ladder> L(k);
    for (int i = 0; i < k; i++)
    {
        cin >> L[i].r1 >> L[i].c1 >> L[i].r2 >> L[i].c2 >> L[i].h;
        pts.push_back({L[i].r1, L[i].c1});
        pts.push_back({L[i].r2, L[i].c2});
    }

    sort(all(pts));
    pts.erase(unique(all(pts)), pts.end());

    auto get_id = [&](int r, int c)
    {
        return lower_bound(all(pts), make_pair(r, c)) - pts.begin();
    };

    int total_nodes = pts.size();
    vector<vector<node>> floor_nodes(n + 1);
    for (int i = 0; i < total_nodes; i++)
    {
        floor_nodes[pts[i].first].push_back({pts[i].first, pts[i].second, i});
    }

    vector<vector<edge>> adj(total_nodes);
    for (int i = 1; i <= n; i++)
    {
        sort(all(floor_nodes[i]), [](node a, node b)
             { return a.c < b.c; });
        for (size_t j = 0; j + 1 < floor_nodes[i].size(); j++)
        {
            ll dist = (ll)(floor_nodes[i][j + 1].c - floor_nodes[i][j].c) * x[i];
            adj[floor_nodes[i][j].id].push_back({floor_nodes[i][j + 1].id, dist});
            adj[floor_nodes[i][j + 1].id].push_back({floor_nodes[i][j].id, dist});
        }
    }

    for (auto &l : L)
    {
        adj[get_id(l.r1, l.c1)].push_back({(int)get_id(l.r2, l.c2), (ll)-l.h});
    }

    priority_queue<pll, vector<pll>, greater<pll>> pq;
    vll dist(total_nodes, INF);

    int start_id = get_id(1, 1);
    int end_id = get_id(n, m);

    dist[start_id] = 0;
    pq.push({0, start_id});

    while (!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();
        if (d > dist[u])
            continue;

        for (auto &e : adj[u])
        {
            if (dist[e.to] > dist[u] + e.w)
            {
                dist[e.to] = dist[u] + e.w;
                pq.push({dist[e.to], e.to});
            }
        }
    }

    if (dist[end_id] >= INF)
        cout << "NO ESCAPE" << endl;
    else
        cout << dist[end_id] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
   // precompute();
   // freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}