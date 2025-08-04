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

typedef struct
{
    int s;
    int e;
    int p;
} order;
bool cmp(order &a, order &b)
{
    return a.e < b.e;
}

int lastValid(vector<order> &Orders, int idx)
{
    int l = 0, r = idx - 1, ans = -1;
    while (l <= r)
    {
        int m = l + (r - l) / 2;
        if (Orders[m].e <= Orders[idx].s)
        {
            ans = m;
            l = m + 1;
        }
        else
        {
            r = m - 1;
        }
    }
    return ans;
}

void solve()
{
    int n;
    cin >> n;
    vector<order> Orders;
    for (int i = 0; i < n; i++)
    {
        int s, d, p;
        cin >> s >> d >> p;
        Orders.pb({s, s + d, p});
    }
    sort(all(Orders), cmp);
    vector<ll> dp(n);
    dp[0] = Orders[0].p;
    for (int i = 1; i < n; i++)
    {
        // donot include this ith order;
        dp[i] = dp[i - 1];
        ll include = Orders[i].p;
        int last = lastValid(Orders, i);
        if (last != -1)
        {
            include += dp[last];
        }
        dp[i] = max(dp[i], include);
    }

    cout << dp[n - 1] << endl;
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