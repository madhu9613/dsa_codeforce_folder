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

void solve()
{
    int n;
    cin >> n;

    int k = 0;
    while ((1 << k) <= n)
        k++;
    if ((1 << k) <= n)
        k++;

    vector<string> s(k);
    for (int i = 0; i < k; ++i)
        cin >> s[i];

    vi p(k);
    iota(p.begin(), p.end(), 0);

    int ans = 0;

    do
    {
       vi seen(n + 1, 0);
        bool ok = true;

        for (int i = 0; i < n; ++i)
        {
            int val = 0;
            for (int j = 0; j < k; ++j)
            {
                if (s[p[j]][i] == '1')
                {
                    val |= (1 << j);
                }
            }

            if (val < 1 || val > n || seen[val])
            {
                ok = false;
                break;
            }
            seen[val] = 1;
        }

        if (ok)
            ans++;

    } while (next_permutation(p.begin(), p.end()));

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
   // precompute();
   // freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}