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

// Fast exponentiation (a^b % mod)
ll modpow(ll a, ll b, ll mod = MOD)
{
    ll res = 1;
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

// GCD
ll gcd(ll a, ll b)
{
    return b ? gcd(b, a % b) : a;
}

// LCM
ll lcm(ll a, ll b)
{
    return a / gcd(a, b) * b;
}

void solve()
{
    int n, m;
    cin >> n >> m;

    // Edge case: if n <= 2, choosing n-2 means 0 products.
    if (n <= 2)
    {
        cout << 0 << "\n";
        return;
    }

    vector<vi> rating(n, vector<int>(m));
    vi max_rating(n, 0);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> rating[i][j];
            max_rating[i] = max(max_rating[i], rating[i][j]);
        }
    }

    vector<vi> trans(m, vi(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            trans[j][i] = rating[i][j];
        }
    }

    int left = 0;
    int right = 1e9; // Safely bound to max constraint (10^9)
    int ans = 0;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        bool base_cov = true;

        for (int i = 0; i < n; i++)
        {
            if (max_rating[i] < mid)
            {
                base_cov = false;
                break;
            }
        }

        if (!base_cov)
        {
            right = mid - 1;
            continue;
        }

        bool pos = false;
        vector<pair<int, int>> edges;

        for (int j = 0; j < m; j++)
        {
            int cnt = 0;
            int c1 = -1, c2 = -1;

            for (int i = 0; i < n; i++)
            {
                if (trans[j][i] >= mid)
                {
                    cnt++;
                    if (cnt == 1)
                        c1 = i;
                    else if (cnt == 2)
                        c2 = i;

                    if (cnt == 3)
                    {
                        pos = true;
                        break;
                    }
                }
            }

            if (pos)
            {
                break;
            }

            if (cnt == 2)
            {
                edges.push_back({c1, c2});
            }
        }

        if (pos)
        {
            ans = mid;
            left = mid + 1;
            continue;
        }

        if (edges.empty())
        {
            right = mid - 1;
            continue;
        }

        int u = edges[0].first;
        int v = edges[0].second;

        // FIX: MUST initialize to false!
        bool disjoint = false;

        unordered_set<int> adjU, adjV;
        for (const auto &e : edges)
        {
            if (e.first != u && e.first != v && e.second != u && e.second != v)
            {
                disjoint = true;
                break;
            }

            if (e.first == u && e.second == v)
                continue;
            if (e.first == v && e.second == u)
                continue;

            if (e.first == u)
                adjU.insert(e.second);
            else if (e.second == u)
                adjU.insert(e.first);
            else if (e.first == v)
                adjV.insert(e.second);
            else if (e.second == v)
                adjV.insert(e.first);
        }

        if (!disjoint)
        {
            if (!adjU.empty() && !adjV.empty())
            {
                if (adjU.size() > 1 || adjV.size() > 1)
                {
                    disjoint = true;
                }
                else if (*adjU.begin() != *adjV.begin())
                {
                    disjoint = true;
                }
            }
        }

        if (disjoint)
        {
            ans = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--)
        solve();

    return 0;
}