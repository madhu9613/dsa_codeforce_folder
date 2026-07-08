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
// a[i]<=500;
//

const int MAX_VAL=1<<9;
const int INF=1e6;

void solve()
{
    int n;
    if (!(cin >> n))
        return;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<int> dp(MAX_VAL, INF);
    dp[0] = -1;

    for (int x : a)
    {
        for (int s = 0; s < MAX_VAL; ++s)
        {
            if (dp[s] < x)
            {
                dp[s ^ x] = min(dp[s ^ x], x);
            }
        }
    }

    vector<int> res;
    for (int s = 0; s < MAX_VAL; ++s)
    {
        if (dp[s] != INF)
        {
            res.push_back(s);
        }
    }

    cout << res.size() << "\n";
    for (int i = 0; i < res.size(); ++i)
    {
        cout << res[i] << (i == res.size() - 1 ? "" : " ");
    }
    cout << "\n";
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