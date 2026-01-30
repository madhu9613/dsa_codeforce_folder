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
    int n,m;cin>>n>>m;
    priority_queue<ll>a,b;
    for(int i=0;i<n;i++)
    {
        ll x;cin>>x;
        a.push(x);
    }
    for(int i=0;i<m;i++)
    {
        ll x;cin>>x;
        b.push(x);
    }
    bool alice=true;
    while (!a.empty() && !b.empty())
    {
        if(alice)
        {
            ll x=a.top();;
            ll y=b.top();b.pop();
            if(y>x)
            {
                b.push(y-x);
            }


        }
        else{
            ll x=b.top(); 
            ll y =a.top(); a.pop();
            if(y>x)
            {
                a.push(y-x);
            }
        }
        alice=!alice;
    }

    if(b.empty())
    {
        cout<<"Alice"<<endl;
    }else{
        cout<<"Bob"<<endl;
    }
    

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