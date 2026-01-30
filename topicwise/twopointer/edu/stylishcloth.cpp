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
//diff is minimum;

void solve() {
    vector<int>a[4];
    for(int i=0;i<4;i++)
    {
        int n;cin>>n;
    a[i].resize(n);
    for(int j=0;j<n;j++)
    {
        cin>>a[i][j];
    }
    sort(all(a[i]));
    }
    int i=0,j=0,k=0,l=0;
    int best=INT_MAX;
    vector<int>ans(4);
    while(i<a[0].size() && j<a[1].size() && k<a[2].size() &&l<a[3].size())
    {
         int cmin=min({a[0][i],a[1][j],a[2][k],a[3][l]});
         int cmax = max({a[0][i], a[1][j], a[2][k], a[3][l]});
         if(cmax-cmin<best)
         {
            best=cmax-cmin;
            ans={a[0][i],a[1][j],a[2][k],a[3][l]};
         }
         if(cmin==a[0][i]) i++;
         else if(cmin==a[1][j]) j++;
         else if(cmin==a[2][k]) k++;
         else l++;
    }
    for(int x:ans)
    {
        cout<<x<<" ";
    }cout<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
   
    while (t--)
        solve();

    return 0;
}