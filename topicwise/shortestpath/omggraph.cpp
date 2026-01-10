// https://codeforces.com/problemset/problem/2117/G

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

ll lcm(ll a, ll b)
{
    return a / gcd(a, b) * b;
}
ll pow(ll a, ll b, ll m)
{
    if (b == 0)
        return 1;
    if (b == 1)
        return a % m;
    ll temp = pow(a, b / 2, m);
    if (b % 2 == 0)
    {
        return (temp * temp) % m;
    }
    else
    {
        return (a * (temp * temp) % m) % m;
    }
}

const int MOD = 1e9 + 7;
const int INF = INT_MAX;
const ll LINF = 1e18;

const int MAXN = 40005;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, ll>>> adj(n + 1);
    vector<array<ll, 3>> edges(m);

    for (int i = 0; i < m; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        edges[i]={a,b,w};
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }
    auto maxdij = [&](int u) -> vector<ll>
    {
        vector<ll> dist(n + 1, INF);
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;

        dist[u] = 0;
        pq.push({0, u});
        while (!pq.empty())
        {
            auto [cost, node] = pq.top();
            pq.pop();
            if (cost > dist[node])
                continue;

            for (auto [v, w] : adj[node])
            {
                ll newdist = max(cost, w);
                if (newdist < dist[v])
                {
                    dist[v] = newdist;
                    pq.push({newdist, v});
                }
            }
        }
        return dist;
    };

    auto maxcost1=maxdij(1);
    auto maxcost2=maxdij(n);
    ll ans=INF;
    for(auto &e:edges)
    {
        ll u=e[0],v=e[1],w=e[2];
        ans=min(ans,
        w+max({w,maxcost1[u],maxcost2[v]}));

        ans=min(ans,
        w+max({w,maxcost1[v],maxcost2[u]}));

    }
    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--)
        solve();

    return 0;
}