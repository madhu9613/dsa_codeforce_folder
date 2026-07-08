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

const int  MAXN=4e5+5;
bool apos[MAXN],aneg[MAXN],bpos[MAXN],bneg[MAXN],canpos[MAXN],canneg[MAXN];
;
void solve()
{
    int n, m, q;
    cin >> n >> m >> q;

    vector<int> a(n), b(m);

    int A = 0, B = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        A += a[i];
    }

    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
        B += b[i];
    }

    memset(apos, 0, sizeof(apos));
    memset(aneg, 0, sizeof(aneg));
    memset(bpos, 0, sizeof(bpos));
    memset(bneg, 0, sizeof(bneg));
    memset(canpos, 0, sizeof(canpos));
    memset(canneg, 0, sizeof(canneg));


    for (int i = 0; i < n; i++)
    {
        int val = A - a[i];
        if (abs(val) >= MAXN)
            continue;

        if (val >= 0)
            apos[val] = true;
        else
            aneg[-val] = true;
    }

    for (int i = 0; i < m; i++)
    {
        int val = B - b[i];
        if (abs(val) >= MAXN)
            continue;

        if (val >= 0)
            bpos[val] = true;
        else
            bneg[-val] = true;
    }

    for (int i = 1; i < MAXN; i++)
    {
        for (int j = 1; j < MAXN; j++)
        {
            if (i * j >= MAXN)
                break;

            if (apos[i] && bpos[j])
                canpos[i * j] = true;
            if (aneg[i] && bneg[j])
                canpos[i * j] = true;

            if (apos[i] && bneg[j])
                canneg[i * j] = true;
            if (aneg[i] && bpos[j])
                canneg[i * j] = true;
        }
    }

    while (q--)
    {
        int x;
        cin >> x;

        if (x > 0)
        {
            cout << (canpos[x] ? "YES\n" : "NO\n");
        }
        else
        {
            cout << (canneg[-x] ? "YES\n" : "NO\n");
        }
    }
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
