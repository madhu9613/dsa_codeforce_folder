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
const int MAXN = 2e5 + 5;

ll modpow(ll a, ll b, ll mod = MOD)
{
    ll res = 1;
    a %= mod;
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

ll gcd(ll a, ll b)
{
    return b ? gcd(b, a % b) : a;
}

ll lcm(ll a, ll b)
{
    return a / gcd(a, b) * b;
}

struct state
{
    ll cost;
    int u;
    int s;
    bool operator>(const state &other) const
    {
        return cost > other.cost;
    }
};
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, ll>>> adj(n + 1);
    vi slow(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    for (int i = 1; i <= n; i++)
    {

        cin >> slow[i];
    }

    //
    // dist[i][s]; // at i i own bike with slowness sl
    vector<vector<ll>> dist(n + 1, vector<ll>(1002, INF));
    // state:cost,u,s;

    priority_queue<state, vector<state>, greater<state>> pq;
    dist[1][slow[1]] = 0;
    pq.push({0LL, 1, slow[1]});
    while (!pq.empty())
    {
        auto [d, u, s] = pq.top();
        pq.pop();
        if (d > dist[u][s])
        {

            continue;
        }

        for (auto [v, w] : adj[u])
        {

            ll cost = 1LL * w * s;
            int news = min(s, slow[v]);
            if (dist[v][news] > d + cost)
            {
                dist[v][news] = d + cost;
                pq.push({dist[v][news], v, news});
            }
        }
    }

    ll ans=INF;
    for(int s=0;s<=1000;s++){
        ans=min(ans,dist[n][s]);
    }

    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // precompute();
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}