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
bool cmp(vi &a,vi &b)
{

    return (a[0]<b[0]) or (a[0]==b[0] and a[1]>b[1]);

}
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)

        {

            int x;
            cin >> x;

            a.pb({x, i * m + j});
        }
    }
    sort(all(a));
    ll ans=0;
    for(int i=0;i<n;i++)
    {
        sort(a.begin()+(m*i),a.begin()+(m*(i+1)),cmp);
        for(int j=0;j<m;j++)

        {
            for(int k=0;k<j;k++)

            {
                if(a[i*m+k][1]<a[i*m+j][1]) ans++;
            }
        }
    }
    cout<<ans<<endl;
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