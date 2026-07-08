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

// Fast exponentiation
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


ll dp[65][2][2][2][2][2];
bool vis[65][2][2][2][2][2];

vi L, R;

ll f(int pos, int fl1, int fr1, int fl2, int fr2, int less_ab) {
    if (pos == -1) return 0;

    if (vis[pos][fl1][fr1][fl2][fr2][less_ab])
        return dp[pos][fl1][fr1][fl2][fr2][less_ab];

    vis[pos][fl1][fr1][fl2][fr2][less_ab] = true;

    ll ans = 0;

    int lbit = L[pos];
    int rbit = R[pos];

    for (int abit = 0; abit <= 1; abit++) {
        for (int bbit = 0; bbit <= 1; bbit++) {

            if (!less_ab && abit > bbit) continue;

            if (!fl1 && abit < lbit) continue;
            if (!fr1 && abit > rbit) continue;

            if (!fl2 && bbit < lbit) continue;
            if (!fr2 && bbit > rbit) continue;

            int nfl1 = fl1 || (abit > lbit);
            int nfr1 = fr1 || (abit < rbit);

            int nfl2 = fl2 || (bbit > lbit);
            int nfr2 = fr2 || (bbit < rbit);

            int nless_ab = less_ab || (abit < bbit);

            ll val = (abit ^ bbit) ? (1LL << pos) : 0;

            val += f(pos - 1, nfl1, nfr1, nfl2, nfr2, nless_ab);

            ans = max(ans, val);
        }
    }

    return dp[pos][fl1][fr1][fl2][fr2][less_ab] = ans;
}


void solve() {
    ll l, r;
    cin >> l >> r;

    memset(vis, 0, sizeof(vis));
    L.clear();
    R.clear();

    // store bits (LSB at index 0)
    for (int i = 0; i <= 60; i++) {
        L.push_back((l >> i) & 1);
        R.push_back((r >> i) & 1);
    }

    cout << f(60, 0, 0, 0, 0, 0) << "\n";
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}