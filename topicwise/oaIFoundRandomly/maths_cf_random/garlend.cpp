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

const int MOD = 1000000007;
const int MAXN = 2e5 + 5;
const int INF=1e9;
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


int dp[105][105][2];

void solve()
{
    int n;
    cin >> n;
    vi p(n);
    int t_odd = (n + 1) / 2;
    int t_even = n / 2;

    // Track zeros to make even_left calculation trivial
    vi pref_z(n, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
        if (p[i] != 0)
        {
            if (p[i] % 2)
            {
                t_odd--;
            }
            else
            {
                t_even--;
            }
        }
        // Build prefix sum of zeros
        pref_z[i] = (p[i] == 0) + (i > 0 ? pref_z[i - 1] : 0);
    }

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            dp[i][j][0] = dp[i][j][1] = INF;
        }
    }

    if (p[0] != 0)
    {
        dp[0][t_odd][p[0] % 2] = 0;
    }
    else
    {
        if (t_odd > 0)
            dp[0][t_odd - 1][1] = 0;
        if (t_even > 0)
            dp[0][t_odd][0] = 0;
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j <= t_odd; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                if (dp[i][j][k] == INF)
                    continue;

                if (p[i + 1] != 0)
                {
                    int nxtp = p[i + 1] % 2;
                    int cost = (k != nxtp);
                    dp[i + 1][j][nxtp] = min(dp[i + 1][j][nxtp], dp[i][j][k] + cost);
                }
                else
                {
                    // Bulletproof even_left calculation
                    int odds_placed = t_odd - j;
                    int evens_placed = pref_z[i] - odds_placed;
                    int even_left = t_even - evens_placed;

                    if (even_left > 0)
                    { // FIXED condition
                        int cost = (k != 0);
                        dp[i + 1][j][0] = min(dp[i + 1][j][0], dp[i][j][k] + cost);
                    }

                    if (j > 0)
                    {
                        int cost = (k != 1);
                        dp[i + 1][j - 1][1] = min(dp[i + 1][j - 1][1], dp[i][j][k] + cost);
                    }
                }
            }
        }
    }

    int ans = INF;
    for (int j = 0; j <= t_odd; ++j)
    {
        ans = min({ans, dp[n - 1][j][0], dp[n - 1][j][1]});
    }

    cout << ans << "\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
   // precompute();
   // freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);
    int t = 1;
    while (t--) solve();
    return 0;
}