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
    int n, k, q;
    cin >> n >> k >> q;

    vll a(k + 1), b(k + 1);
    a[0] = 0;
    b[0] = 0;

    for (int i = 1; i <= k; i++)
        cin >> a[i];
    for (int i = 1; i <= k; i++)
        cin >> b[i];

    while (q--)
    {
        ll c;
        cin >> c;

        if (c == 0)
        {
            cout << 0 << " ";
            continue;
        }

        int i = lower_bound(all(a), c) - a.begin();

        if (a[i] == c)
        {
            cout << b[i] << " ";
            continue;
        }

        ll dist = c - a[i - 1];
        ll tdist = a[i] - a[i - 1];
        ll ttime = b[i] - b[i - 1];

        ll ans = b[i - 1] + (dist * ttime) / tdist;

        cout << ans << " ";
    }

    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}