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
    vll a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    unordered_map<ll, ll> len;
    unordered_map<ll, ll> last;
    vll dp(n + 1);
    vll prev(n + 1, -1);
    int bestlen = 0;
    int bestend = 1;
    for (int i = 1; i <= n; ++i)
    {
        ll val = a[i];
        if (len.count(val - 1))
        {
            dp[i] = len[val - 1] + 1;
            prev[i] = last[val - 1];
        }
        else
        {
            dp[i] = 1;
            prev[i] = -1;
        }
        if (dp[i] > len[val])
        {
            len[val] = dp[i];
            last[val] = i;
        }
        if (dp[i] > bestlen)
        {
            bestlen = dp[i];
            bestend = i;
        }
    }

    cout<<bestlen<<endl;
    vi idx;
    for(int c=bestend;c!=-1;c=prev[c])
    {
        idx.pb(c);
    }
    reverse(all(idx));
    for(int i:idx)
    {
        cout<<i<<" ";
    }cout<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    
    while (t--)
        solve();
    return 0;
}