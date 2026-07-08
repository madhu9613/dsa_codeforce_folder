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

// Fast exponentiation (a^b % mod)
ll modpow(ll a, ll b, ll mod = MOD) {
    ll res = 1;
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

// GCD
ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

// LCM
ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

void solve()
{
    int n;
    cin >> n;

    vector<vector<pii>> adj(n + 1); // {neighbor, edge_index}

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }

    vi ans(n - 1, -1);

    int deg3 = -1;

    for (int i = 1; i <= n; i++)
    {
        if ((int)adj[i].size() >= 3)
        {
            deg3 = i;
            break;
        }
    }

    int cur = 0;

    if (deg3 != -1)
    {
        for (auto [v, idx] : adj[deg3])
        {
            if (cur < 3)
            {
                ans[idx] = cur++;
            }
        }

        for (int i = 0; i < n - 1; i++)
        {
            if (ans[i] == -1)
            {
                ans[i] = cur++;
            }
        }
    }
    else
    {
        for (int i = 0; i < n - 1; i++)
        {
            ans[i] = i;
        }
    }

    for (int x : ans)
    {
        cout << x << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}