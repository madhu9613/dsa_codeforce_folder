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

vi nxt;
int get_next(int v)
{
    if (nxt[v] == v)
    {
        return v;
    }
    return nxt[v] = get_next(nxt[v]);
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> fight(m);
    for (int i = 0; i < m; i++)
    {
        int l, r, x;
        cin >> l >> r >> x;
        fight[i] = {l, r, x};
    }

    // FIX: Resize to n + 2 to avoid segmentation fault when accessing n + 1
    nxt.resize(n + 2);
    for (int i = 1; i <= n + 1; i++)
    {
        nxt[i] = i;
    }

    vi ans(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        int l = fight[i][0];
        int r = fight[i][1];
        int w = fight[i][2];

        int cur = get_next(l);
        while (cur <= r)
        {
            if (cur == w)
            {
                cur = cur + 1;
                // We don't call continue here because we want the
                // get_next(cur) compression to run at the bottom of the loop
            }
            else
            {
                ans[cur] = w;
                nxt[cur] = cur + 1;
                cur = cur + 1;
            }

            cur = get_next(cur);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--)
        solve();

    return 0;
}