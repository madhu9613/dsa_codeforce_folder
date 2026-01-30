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

void solve()
{
    int n, s1, s2;
    cin >> n >> s1 >> s2;

    int m1;
    cin >> m1;
    vector<vector<int>> adj1(n + 1), adj2(n + 1);

    for (int i = 0; i < m1; i++)
    {
        int a, b;
        cin >> a >> b;
        adj1[a].push_back(b);
        adj1[b].push_back(a); 
    }

    int m2;
    cin >> m2;
    for (int i = 0; i < m2; i++)
    {
        int a, b;
        cin >> a >> b;
        adj2[a].push_back(b);
        adj2[b].push_back(a);
    }

    vector<int> need(n + 1, 0);
    for (int v = 1; v <= n; v++)
    {
        unordered_set<int> st(adj1[v].begin(), adj1[v].end());
        for (int u : adj2[v])
        {
            if (st.count(u))
            {
                need[v] = 1;
                break;
            }
        }
    }

    vector<vector<ll>> dist(n + 1, vector<ll>(n + 1, LINF));
    priority_queue<
        pair<ll, pair<int, int>>,
        vector<pair<ll, pair<int, int>>>,
        greater<>>
        pq;

    dist[s1][s2] = 0;
    pq.push({0, {s1, s2}});

    while (!pq.empty())
    {
        auto [cd, p] = pq.top();
        pq.pop();
        int u1 = p.first;
        int u2 = p.second;

        if (cd != dist[u1][u2])
            continue;

        for (int v1 : adj1[u1])
        {
            for (int v2 : adj2[u2])
            {
                ll nd = cd + llabs(v1 - v2);
                if (nd < dist[v1][v2])
                {
                    dist[v1][v2] = nd;
                    pq.push({nd, {v1, v2}});
                }
            }
        }
    }

    ll ans = LINF;
    for (int v = 1; v <= n; v++)
    {
        if (need[v])
        {
            ans = min(ans, dist[v][v]);
        }
    }

    cout << (ans == LINF ? -1 : ans) << '\n';
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