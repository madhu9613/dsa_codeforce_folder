//https://codeforces.com/problemset/problem/2109/D

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
    int n, m, l;
    cin >> n >> m >> l;

    vector<int> a(l);
    ll S = 0;
    int oddCnt = 0, minOdd = INT_MAX;
    for (int i = 0; i < l; i++)
    {
        cin >> a[i];
        S += a[i];
        if (a[i] & 1)
        {
            oddCnt++;
            minOdd = min(minOdd, a[i]);
        }
    }

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // dist[node][parity]
    vector<array<int, 2>> dist(n + 1, {INF, INF});
    queue<pair<int, int>> q;

    dist[1][0] = 0;
    q.push({1, 0});

    while (!q.empty())
    {
        auto [u, p] = q.front();
        q.pop();
        for (int v : adj[u])
        {
            if (dist[v][p ^ 1] > dist[u][p] + 1)
            {
                dist[v][p ^ 1] = dist[u][p] + 1;
                q.push({v, p ^ 1});
            }
        }
    }

    auto maxSumParity = [&](int p) -> ll
    {
        if ((S & 1) == p)
            return S;
        if (oddCnt == 0)
            return -1;
        return S - minOdd;
    };

    string ans(n, '0');
    for (int i = 1; i <= n; i++)
    {
        bool ok = false;
        for (int p = 0; p < 2; p++)
        {
            int need = dist[i][p];
            if (need == INF)
                continue;
            if (maxSumParity(p) >= need)
            {
                ok = true;
                break;
            }
        }
        ans[i - 1] = ok ? '1' : '0';
    }

    cout << ans << '\n';
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