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
    int n;
    
    ll y;cin>>n>>y;
    vi c(n);
    int maxi=INT_MIN;
 

    for(int i=0;i<n;i++)
    {
        cin>>c[i];
        maxi=max(maxi,c[i]);
        
    }
    vector<ll> cnt(maxi + 1, 0);
    for(int x:c)
    {
        cnt[x]++;
    }

    vll pref(maxi+1,0);

    for(int i=1;i<=maxi;i++)
    {
        pref[i]=pref[i-1]+cnt[i];
    }
    ll ans=LLONG_MIN; 

    for(int x=2;x<=max(2,maxi);x++)
    {
        ll income=0;
        int maxk=(maxi+x-1)/x;
        for(int k=1;k<=maxk;k++)
        {
            int left=(k-1)*x+1;
            int right=min(k*x,maxi);
            if(left>right) break;
            ll newcnt=pref[right]-pref[left-1];
            ll print=max(0LL,newcnt-cnt[k]);
            income+=k*newcnt-y*print;
        }
        ans=max(ans,income);
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