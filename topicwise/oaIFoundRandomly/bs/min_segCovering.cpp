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
const int MAXN = 5e5 + 5;

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

const int LOG = 20;
int up[MAXN][LOG];
void solve()
{
    int n, m;
    cin >> n >> m;
    
    // using 0 interval';
    for (int i = 0; i < MAXN; i++)
    {
        up[i][0] = i;
    }
    //up[i][k] ->starting at point (i) what is the max posn i can go using k intervals;
    
    for (int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;
        up[l][0] = max(up[l][0], r);
    }
    for (int i = 1; i < MAXN; ++i)
    {
        up[i][0] = max(up[i][0], up[i - 1][0]);
    }

    for (int k = 1; k < LOG; k++)
    {
        for (int i = 0; i < MAXN; i++)
        {

            up[i][k] = up[up[i][k - 1]][k - 1];
        }
    }
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        int cur = x;
        int ans = 0;
        for (int k = LOG - 1; k >= 0; k--)
        {
            if (up[cur][k] < y)
            {
                ans += (1 << k);
                cur = up[cur][k];
            }
        }
        if (up[cur][0] >= y)
        {
            cout << ans + 1 << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // precompute();
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t = 1;
    while (t--)
        solve();
    return 0;
}