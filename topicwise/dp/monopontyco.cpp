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
    vi a1(n+1),a2(n+1);
    for(int i=1;i<=n;i++)cin>>a1[i];
    for(int i=1;i<=n;i++)cin>>a2[i];
    vi prefmin(n+1),prefmax(n+1),suffmin(n+2),suffmax(n+2);
    prefmin[1]=a1[1];
    prefmax[1]=a1[1];
    for(int i=2;i<=n;i++)
    {
        prefmin[i]=min(prefmin[i-1],a1[i]);
        prefmax[i]=max(prefmax[i-1],a1[i]);
    }

    suffmin[n]=a2[n];
    suffmax[n]=a2[n];
    for(int i=n-1;i>=1;i-- )
    {
        suffmin[i]=min(suffmin[i+1],a2[i]);
        suffmax[i]=max(suffmax[i+1],a2[i]);
    }

    vector<pair<int,int>>intervals;
    for(int k=1;k<=n;k++)
    {
        int l=min(prefmin[k],suffmin[k]);
        int r=max(prefmax[k],suffmax[k]);
        intervals.push_back({l,r});
    }
    sort(intervals.begin(),intervals.end(),
[](auto &a,auto &b){
    return a.first>b.first;
});

int maxi=2*n;
vi minr(maxi+2,INT_MAX);
int ptr=0;
int bestr=INT_MAX;
for(int l=maxi;l>=1;l--)
{
    while(ptr<n && intervals[ptr].first>=l)
    {
        bestr=min(bestr,intervals[ptr].second);
        ptr++;
    }
    minr[l]=bestr;
}

ll ans=0;
for(int l=1;l<=maxi;l++)
{
    if(minr[l]<=maxi)
   {
    ans+=max(0,maxi-minr[l]+1);
   }
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