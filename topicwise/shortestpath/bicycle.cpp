// https://codeforces.com/problemset/problem/1915/G

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

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}
ll pow(ll a,ll b,ll m)
{
if(b==0)
 return 1;
if(b==1) return a%m;
 ll temp=pow(a,b/2,m);
 if(b%2==0)
 {
 return (temp*temp)%m;
}
else
{
return (a*(temp*temp)%m)%m ;
}
}

const int MOD = 1e9 + 7;
const int INF = INT_MAX;
const ll LINF = 1e18;

const int MAXN = 40005;

struct state
{
    ll dist;
    int u;
    int best;
    bool operator>(const state &other) const
    {
        return dist > other.dist;
    }
};

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, ll>>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        ll w;
        cin >> a >> b >> w;
        adj[a].pb({b, w});
        adj[b].pb({a, w});
    }

    vector<int> s(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> s[i];

    // dist[u][best_slowness]
    vector<vector<ll>> dist(n + 1, vector<ll>(1001, LINF));

    priority_queue<state, vector<state>, greater<>> pq;

    dist[1][s[1]] = 0;
    pq.push({0, 1, s[1]});

    while (!pq.empty())
    {
        auto cur = pq.top();
        pq.pop();
        ll cost = cur.dist;
        int u = cur.u;
        int best = cur.best;

        if (cost > dist[u][best])
            continue;

        // Buy bike at u (only if better)
        if (s[u] < best)
        {
            int new_best = s[u];
            if (dist[u][new_best] > cost)
            {
                dist[u][new_best] = cost;
                pq.push({cost, u, new_best});
            }
        }

        // Move to neighbors
        for (auto [v, w] : adj[u])
        {
            ll newcost = cost + w * best;
            bool bad=false;
            for(int b=1;b<=best;b++)
            {
                if(dist[v][b]<=newcost)
                {
                    bad=true;
                     break;
                }
            }
            if(bad) continue;
            if(dist[v][best]>newcost)
            {
                dist[v][best]=newcost;
                pq.push({newcost,v,best});
            }
        }
    }

    ll ans = LINF;
    for (int i = 1; i <= 1000; i++)
    {
        ans = min(ans, dist[n][i]);
    }

    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--)
        solve();

    return 0;
}