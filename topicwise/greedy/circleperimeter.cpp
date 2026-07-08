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
    ll r;
    cin >> r;

    auto f = [&](ll R) -> ll
    {
        ll res = 0;
        for (ll x = 0; x < R; x++)
        {
            ll val = R * R - x * x - 1;
            if (val < 0)
                continue;

            ll y = sqrtl(val);

            while ((y + 1) * (y + 1) <= val)
            {
                y++;
            }
            while (y * y > val)
            {
                y--;
            }
            res += y;
        }

        return 1 + 4 * res;
    };

    cout << f(r + 1) - f(r) << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}