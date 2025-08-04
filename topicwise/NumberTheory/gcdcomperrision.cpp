#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define max3(a, b, c) max(max(a, b), c)
#define max4(a, b, c, d) max(max(a, b), max(c, d))
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()
#define endl '\n'

ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}
const int MOD = 1e9 + 7;
const int INF = INT_MAX;

void solve()
{
    int n;
    cin >> n;
    vi a(2 * n);
    vi even, odd;
    for (int i = 0; i < 2 * n; i++)
    {
        cin >> a[i];
        if (a[i] % 2 == 0)
        {
            even.pb(a[i]);
        }
        else
        {
            odd.pb(a[i]);
        }
    }

    vector<pair<int, int>> res;
    for (int i = 0; i < odd.size() - 1; i++)
    {
        res.pb({odd[i], odd[i + 1]});
    }
    for (int i = 0; i < even.size() - 1; i++)
    {
        res.pb({even[i], even[i + 1]});
    }

    for (auto &[a, b] : res)
    {
        cout << a << " " << b << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}