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
//     int n,m,q;cin>>n>>m>>q;
//     vll a(n),b(m);
//     for(int i=0;i<n;i++) cin>>a[i];
//     for(int i=0;i<m;i++) cin>>b[i];

//     sort(rall(a));
//     sort(rall(b));
//     vll prefixA(n+1,0),prefixB(m+1,0);
//     for(int i=1;i<=n;i++)
//     {
//         prefixA[i]=prefixA[i-1]+a[i-1];
//     }
//     for(int i=1;i<=m;i++)
//     {
//         prefixB[i]=prefixB[i-1]+b[i-1];
//     }
//     while(q--)
//     {
//         int x,y,z;cin>>x>>y>>z;
//         int left=max(0,z-y);
//         int right=min(x,z);

//         int l = left;
//         int r = right;

//         //we are adding f(k)+g(k) when k increase f is increasin and when k increase g() is decreasing so they reach a mountain its like finding peak element 

//         auto F = [&](int k)
//         {
//             return prefixA[k] + prefixB[z - k];
//         };

//         while (l < r)
//         {
//             int mid = l + (r - l) / 2;
//             if (F(mid) < F(mid + 1))
//             {
//                 l = mid + 1;
//             }
//             else
//             {
//                 r = mid;
//             }
//         }

//         ll ans = F(l);
//         cout << ans << "\n";
//     }
// }

void solve()
{
        int n,m,q;cin>>n>>m>>q;
        vll a(n),b(m);
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<m;i++) cin>>b[i];

        sort(rall(a));
        sort(rall(b));
        vll prefixA(n+1,0),prefixB(m+1,0);
        for(int i=1;i<=n;i++)
        {
            prefixA[i]=prefixA[i-1]+a[i-1];
        }
        for(int i=1;i<=m;i++)
        {
            prefixB[i]=prefixB[i-1]+b[i-1];
        }

        // let say no restriction on x and y now use similer merge two sorted array concept and find for every z optimal x and y st x+y=z and sum maximize;
         vi xopt(n+m+1,0);
         int i=0,j=0;
         for(int z=1;z<=n+m;z++)
         {
            if(i<n && (j>=m || a[i]>=b[j]))
            {
                i++;
            }else{
                j++;
            }
            xopt[z]=i;
         }
         while(q--)
         {
            int x,y,z;
            cin>>x>>y>>z;
            int takea=xopt[z];
            takea=min(takea,x);
            takea=max(takea,z-y);
            ll ans=prefixA[takea]+prefixB[z-takea];
            cout<<ans<<endl;
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