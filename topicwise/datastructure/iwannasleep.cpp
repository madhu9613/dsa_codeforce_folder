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

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}
ll pow(ll a,ll b,ll m)
{
if(b==0)
 return 1;
if(b==1) return a%m;
 ll temp=pow(a,b/2,m);
 if(b%2==0)
 {
 return (temp*temp)%m;
}
else
{
return (a*(temp*temp)%m)%m ;
}
}

const int MOD = 1e9 + 7;
const int INF = INT_MAX;
const ll LINF = 1e18;

const int MAXN = 40005;
bool can(ll m, int n, int k, ll x, const vector<ll> &a)
{
    vector<pair<ll, ll>> forbid;

    for (ll ai : a)
    {
        ll L = max(0LL, ai - m + 1);
        ll R = min(x, ai + m - 1);
        if (L <= R)
            forbid.push_back({L, R});
    }

    sort(forbid.begin(), forbid.end());

    ll free_cnt = 0;
    ll cur = 0;

    for (auto &[L, R] : forbid)
    {
        if (cur < L)
            free_cnt += (L - cur);
        cur = max(cur, R + 1);
    }

    if (cur <= x)
        free_cnt += (x - cur + 1);

    return free_cnt >= k;
}

void solve() {
    int n, k;
    ll x;
    cin >> n >> k >> x;

    vector<ll> a(n);
    for (auto &v : a)
        cin >> v;

    ll lo = 0, hi = x + 1;
    while (lo < hi)
    {
        ll mid = (lo + hi + 1) / 2;
        if (can(mid, n, k, x, a))
            lo = mid;
        else
            hi = mid - 1;
    }

    ll best = lo;

    vector<pair<ll, ll>> forbid;
    for (ll ai : a)
    {
        ll L = max(0LL, ai - best + 1);
        ll R = min(x, ai + best - 1);
        if (L <= R)
            forbid.push_back({L, R});
    }
    sort(forbid.begin(), forbid.end());

    vector<ll> ans;
    ll cur = 0;

    for (auto &[L, R] : forbid)
    {
        for (ll p = cur; p < L && (int)ans.size() < k; p++)
            ans.push_back(p);
        cur = max(cur, R + 1);
    }
    for (ll p = cur; p <= x && (int)ans.size() < k; p++)
        ans.push_back(p);

    for (ll v : ans)
        cout << v << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--)
        solve();

    return 0;
}