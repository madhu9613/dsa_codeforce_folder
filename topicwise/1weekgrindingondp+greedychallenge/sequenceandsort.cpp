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

void solve() {

    int n, x;
    cin >> n >> x;

    vector<int> a(n);
    for (int &i : a)
        cin >> i;

    if (is_sorted(a.begin(), a.end()))
    {
        cout << 0 << '\n';
        return;
    }

    const int INF = 1e9;
    vector<vector<int>> dp(n, vector<int>(501, INF));

    for (int i = 0; i < n; i++)
    {
        if (a[i] > x && (i == 0 || a[i - 1] <= x))
            dp[i][x] = 1;

        if (i < n - 1 && a[i] > a[i + 1])
            break;
    }

    int ans = INF;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= 500; j++)
        {
            if (dp[i][j] == INF)
                {
                    continue;
                };

            // Check if rest is sorted
            if (i == n - 1 ||
                (j <= a[i + 1] && is_sorted(a.begin() + i + 1, a.end())))
            {
                ans = min(ans, dp[i][j]);
            }

            bool good = true;

            for (int k = i + 1; k < n; k++)
            {
                int prev = (k == i + 1 ? j : a[k - 1]);

                if (good && a[i] >= prev && a[i] < a[k])
                {
                    dp[k][a[i]] = min(dp[k][a[i]], dp[i][j] + 1);
                }

                if (a[k] < prev)
                    good = false;
            }
        }
    }

    if (ans == INF)
        ans = -1;
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}
//revisit required.
