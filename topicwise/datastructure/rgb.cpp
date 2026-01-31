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

// void solve() {
//     const string t="RGB";
//     int q;cin>>q;
//     while(q--)
//     {
//         int n,k;string s;
//         cin>>n>>k>>s;
//         // need substring of len=k which is also substring of infinite patter;
//         int ans=INT_MAX;
//         for(int i=0;i<n-k+1;i++)
//         {
//             for(int offset=0;offset<3;offset++)
//             {
//                 int cur=0;
//                 for(int pos=0;pos<k;pos++)
//                 {
//                     if(s[i+pos]!=t[(pos+offset)%3])
//                     {
//                         cur++;
//                     }
//                 }
//                 ans=min(ans,cur);
//             }

//         }

//         cout<<ans<<endl;

//     }
// }


void solve()
{
    string t="RGB";
int q;cin>>q;
while(q--)
{
    int n,k;
    string s;
    cin>>n>>k>>s;
    
    vector<vi>pref(3,vi(n+1,0));
    for(int offset=0;offset<3;offset++)
    {
        for(int i=0;i<n;i++)
        {
            pref[offset][i+1]=pref[offset][i]+(s[i]!=t[(i+offset)%3]);
        }
    }

    int ans=INF;
    for(int i=0;i+k<=n;i++)
    {
        for(int offset=0;offset<3;offset++)
        {
            int cur=pref[offset][i+k]-pref[offset][i];
            ans=min(ans,cur);
        }
    }

    cout<<ans<<endl;

}

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while (t--)
        solve();

    return 0;
}