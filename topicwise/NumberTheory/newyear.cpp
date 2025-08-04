#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define max3(a, b, c) max(max(a, b), c)
#define max4(a, b, c, d) max(max(a, b), max(c, d))
#define pii pair<int,int>
#define all(x) (x).begin(), (x).end()
#define endl '\n'

ll gcd(ll a, ll b)
{
 return b == 0 ? a : gcd(b, a % b);
}
const int MOD = 1e9 + 7;
const int INF = INT_MAX;

void solve() {
    ll n;cin>>n;
    set<ll>funs;
    for(ll g=1;g*g<=n;++g)
    {
        if(n%g==0)
        {
            ll k1=n/g;
            ll len1=g;
            ll f1=len1+k1*(len1-1)*(len1)/2;
            funs.insert(f1);

            if(g!=n/g)
            {
                ll k2=g;
                ll len2=n/g;
                ll f2=len2+k2*(len2-1)*len2/2;
                funs.insert(f2);
            }
        }
    }

    for(ll val:funs)
    {
        cout<<val<<" ";
    }cout<<endl;


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    while (t--) solve();
    return 0;
}