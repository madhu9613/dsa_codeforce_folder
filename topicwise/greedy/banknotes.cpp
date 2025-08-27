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

ll power[10];
void process()
{
    power[0]=1;
    for(int i=1;i<=9;i++)
    {
        power[i]=(power[i-1]*10);
    }
}
void solve() {
    int n,k;cin>>n>>k;
    vi a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    ll s=0;
    for(int i=0;i<n;i++)
    {
        if(k<0) break;

        ll icantake=k+1;
        if(i!=n-1)
        {
            icantake=min(icantake,power[a[i+1]-a[i]]-1);

        }
        k-=icantake;
        s+=icantake*power[a[i]];
    }
    cout<<s<<endl;
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    process();
    cin >> t;
    while (t--) solve();
    return 0;
}