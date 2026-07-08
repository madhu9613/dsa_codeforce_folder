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
    ll n, k;
    cin >> n >> k;
    vll a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    ll l = 0, h = 2e12 + 1e6;
    ll best = 0;

    while (l <= h)
    {
        ll mid = l + (h - l) / 2;
        ll cost = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] < mid)
            {
                cost += (mid - a[i]);
                if (cost > k)
                    break;
            }
        }
        if (cost <= k)
        {
            best = mid;
            l = mid + 1;
        }
        else
        {
            h = mid - 1;
        }
    }
    ll cost = 0;
    ll extra = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] < best)
        {
            cost += (best - a[i]);
        }
        else if (a[i] > best)
        {
            
            extra++;
        }
    }

    ll remaining_k = k - cost;
    extra = min(n, extra + remaining_k);

    ll ans = n * (best - 1) + 1 + extra;
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}