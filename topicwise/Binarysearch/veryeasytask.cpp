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
#define int long long
int n,x,y;
bool ispos(int t)
{
    int ineed=n-1;
    int first=t/x;
    int second=t/y;
    if(first+second>=ineed)
    {
        return true;
    }
    return false;
}
void solve() {
cin>>n>>x>>y;
int l=0,r=n*(max(x,y));
int ans=0;
while (l<=r)
{
    int m=l+(r-l)/2;
    if(ispos(m))
    {
        ans=m;
        r=m-1;
    }else{
        l=m+1;
    }
}
cout<<ans+min(x,y)<<endl;

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    while (t--) solve();
    return 0;
}