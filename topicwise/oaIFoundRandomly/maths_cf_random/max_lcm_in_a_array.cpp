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

const int MAXN=1e7+2;
int pos1[MAXN], pos2[MAXN];

void solve()
{
    int n;
    cin >> n;

    vi a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (pos1[a[i]] == 0)
        {
            pos1[a[i]] = i;
        }
        else if (pos2[a[i]] == 0)
        {
            pos2[a[i]] = i;
        }
    }

    ll minLcm = INF;
    int idx1 = -1;
    int idx2 = -1;

    for (int g = 1; g < MAXN; g++)
    {
        ll first = -1, second = -1;
        int i = -1, j = -1;

        for (int mal = g; mal < MAXN; mal += g)
        {
            if (pos1[mal] != 0)
            {
                if (first == -1)
                {
                    first = mal;
                    i = pos1[mal];

                    if (pos2[mal] != 0)
                    {
                        second = mal;
                        j = pos2[mal];
                        break;
                    }
                }
                else
                {
                    second = mal;
                    j = pos1[mal]; 
                    break;
                }
            }
        }

        if (first != -1 && second != -1)
        {
            ll current_lcm = 1LL * first * second / g;
            if (current_lcm < minLcm)
            {
                minLcm = current_lcm;
                idx1 = i;
                idx2 = j;
            }
        }
    }

    if (idx1 > idx2)
    {
        swap(idx1, idx2);
    }

    cout << idx1 << " " << idx2 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}