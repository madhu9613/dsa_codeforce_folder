#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define max3(a, b, c) max(max(a, b), c)
#define max4(a, b, c, d) max(max(a, b), max(c, d))
#define pii pair<int, int>
#define pll pair<ll, ll>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl '\n'

ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
const int MOD = 1e9 + 7;
const int INF = INT_MAX;
const ll LINF = 1e18;

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n + 1);
    vector<int> b, r;

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 1; i <= n; i++)
    {
        char x;
        cin >> x;

        if (x == 'B')
            b.push_back(a[i]);
        else
            r.push_back(a[i]);
    }

    int cur = 1;

    sort(b.begin(), b.end());
    sort(r.begin(), r.end());

    bool is = true;

    for (int i : b)
    {
        if (i >= cur)
            cur++;
        else
        {
            is = false;
            break;
        }
    }

    for (int i : r)
    {
        if (i <= cur)
            cur++;
        else
        {
            is = false;
            break;
        }
    }

    cout << (is ? "YES" : "NO") << endl;
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