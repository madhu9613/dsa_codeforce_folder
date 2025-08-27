#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define max3(a, b, c) max(max(a, b), c)
#define max4(a, b, c, d) max(max(a, b), max(c, d))
#define pii pair<int,int>
#define pll pair<ll,ll>
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
vll h;
bool ispos(int m)
{
    vll curh(all(h));
    int n=h.size()-1;
    for(int i=n;i>=3;--i)
    {
        if(curh[i]<m) return false;

        int d=min(h[i],curh[i]-m)/3;
        curh[i-1]+=d;
        curh[i-2]+=2*d;

    }
    return curh[1]>=m && curh[2]>=m;
}
void solve() {
    int n;cin>>n;
    h.resize(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>h[i];
    }
    int l=0,r=1e9+5,ans=-1;
    while (l<=r)
    {
        int m=l+(r-l)/2;
        if(ispos(m))
         {
            ans=m;
            l=m+1;
         }
         else{
            r=m-1;
         }

    }
    cout<<ans<<endl;

    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}