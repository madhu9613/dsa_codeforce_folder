#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define vi vector<int>
#define vll vector<ll>
#define vpi vector<pii>
#define vpll vector<pll>

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

const ll INF = 1e18;
const int MOD = 1000000007;

// Fast exponentiation (a^b % mod)
ll modpow(ll a, ll b, ll mod = MOD)
{
    ll res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

ll modinv(ll a, ll mod = MOD)
{
    return modpow(a, mod - 2, mod);
}

// GCD
ll gcd(ll a, ll b)
{
    return b ? gcd(b, a % b) : a;
}

// LCM
ll lcm(ll a, ll b)
{
    return a / gcd(a, b) * b;
}

void solve()
{
    // max sum can be  (n*9) if its greater than this its not possible;
    int n, s;
    cin >> n >> s;
    if ((s == 0 && n > 1) || s > 9 * n)
    {
        cout << "-1 -1" << endl;
        return;
    }
    if (n == 1 && s == 0)
    {
        cout << 0 << " " << 0 << endl;
        return;
    }
    int sum = s;
    string larget = "";
    for (int i = 0; i < n; i++)
    {
        int d = min(9, sum);
        larget += (d + '0');
        sum -= d;
    }

    sum = s;
    string smallest = "";
    for (int i = 0; i < n; i++)
    {
        for (int d = (i == 0 ? 1 : 0); d <= 9; d++)
        {
            int rsum = sum - d;
            int posleft = n - i - 1;
            if (rsum >= 0 && rsum <= 9 * posleft)
            {
                smallest += (d + '0');
                sum -= d;
                break;
            }
        }
    }

    cout<<smallest<<" "<<larget<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--)
        solve();

    return 0;
}