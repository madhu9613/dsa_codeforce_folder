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
// Given an array of n
// integers ai Let's say that a segment of this array a[l..r] (1≤l≤r≤n)is
// good if the difference between the maximum and minimum elements on this
// segment is at most k.Your task is to find the number of different good segments.

void solve()
{
  int n;
  ll k;cin>>n>>k;
  vll a(n);
  for(int i=0;i<n;i++)
  {
    cin>>a[i];
  }  
  //max(l--r)-min(l--r)<=k;
  // can use deque; mx -> keep element in dec order->>front ->maximum
  // mn->keep element in inc order->front ->min;

  deque<ll>mx,mn;
  ll ans=0;
  int l=0;
  for(int r=0;r<n;r++)
  {
    while(!mx.empty() && mx.back()<a[r])
    {
        mx.pop_back(); // keep maximum if smaller exist remove;
    }
    mx.push_back(a[r]);

    while(!mn.empty() && mn.back()>a[r])
    {
        mn.pop_back();
    }
    mn.push_back(a[r]);

    while(!mx.empty() && !mn.empty() && mx.front()-mn.front()>k)
    {
        if(a[l]==mx.front()) mx.pop_front();
        if(a[l]==mn.front()) mn.pop_front();
        l++;
    }
    // if (l--r) has max-min<k then l+1..r l+2..r .... all have smaller;
    ans+=(r-l+1);
  }
  cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
   
    while (t--)
        solve();

    return 0;
}