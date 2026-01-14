//https://codeforces.com/problemset/problem/2032/C

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

void solve() {
    int n;cin>>n;
    vll a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(all(a));
    if (n == 3)
    {
        if (a[0] + a[1] > a[2])
            cout << 0 << '\n';
        else
            cout << 1 << '\n';
        return;
    }

    int l = 0, ans = n - 2;
    for (int r = 2; r < n; r++)
    {
        while (r - l >= 2 && a[l] + a[l + 1] <= a[r])
            l++;
        ans = min(ans, n - (r - l + 1));
    }
    cout<<ans<<endl;
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