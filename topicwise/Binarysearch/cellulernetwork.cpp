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
bool isvalidr(vll a, vll b, int r)
{
    int n = a.size();
    int m = b.size();
    for (int city : a)
    {

        auto it = lower_bound(all(b), city);
        bool iscoverd = false;
        if (it != b.end() && abs(*it - city) <= r)
        {
            iscoverd = true;
        }
        if(it!=b.begin()&& abs(*(it-1)-city)<=r)
        {
            iscoverd=true;
        }
        if(!iscoverd)
        {
            return false;
        }
    }
    return true;
}
void solve()
{
    int n, m;cin>>n>>m;
    vll a(n), b(m);
    for (int i = 0; i < n; i++)
    {    cin >> a[i];}
    for (int i = 0; i < m; i++)
        {cin >> b[i];}
    int l=0;int r=2e9;
    int ans=r;
    while (l<=r)
    {
        int m=l+(r-l)/2;
        if(isvalidr(a,b,m))
        {
            ans=m;
           r=m-1;
        }else{
            l=m+1;
        }
        
    }
    cout<<ans<<endl;
    

    


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