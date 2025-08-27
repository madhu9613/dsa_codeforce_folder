#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvll vector<vector<ll>>
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
    vi a(n + 1);

    vvi pos(n + 2);
    // if mex==n+1 pos[n+1] is empty;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        pos[a[i]].pb(i);
    }

    int l = 1;

    vi b;
    while (l <= n)
    {
        int mex = 0;
        int r = l;
        for (; mex <= n + 1; mex++)
        {

            auto it = lower_bound(all(pos[mex]), l);
            if (it == pos[mex].end())
            {

                break;
            }
            r=max(r,*it);
        }
        b.pb(mex);
        l=r+1;
    }

    cout<<b.size()<<endl;
    for(int i:b)
    {
        cout<<i<<" ";
    }cout<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin>>t;
    while (t--)
        solve();
    return 0;
}