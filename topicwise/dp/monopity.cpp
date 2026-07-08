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
    cin>>n;
    vector<vi>a(2,vi(n));
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }

    vector<vector<pair<int, int>>> pos(2 * n + 1);

    for(int i=0;i<2;i++)
    {
        for(int j=0;j<n;j++)
        {
            pos[a[i][j]].push_back({i,j});

        }
    }

    array<set<int>,2>st;
    for(int j=0;j<n;j++)
    {
        st[0].insert(j);
        st[1].insert(j);
    }
    st[0].insert(INF);
    st[1].insert(-INF);
    auto add=[&](int x)
    {
        for(auto [row,col]:pos[x])
        {
            st[row].erase(col);
        }
    };

    auto del=[&](int x)
    {
        for(auto [row,col]:pos[x])
        {
            st[row].insert(col);
        }
    };

    auto check=[&]()->bool{

        if(st[0].count(0)) return false;
        if(st[1].count(n-1)) return false;

        int a=*st[0].begin();
        int b=*st[1].rbegin();
        if(a-1<=b) return false;
        return true;
    };

    ll ans=0;
    int r=0;
    for(int l=1;l<=2*n;l++)
    {
        while(r+1<=2*n && !check())
        {
            add(++r);
        }

        if(!check()) break;

        ans+=2*n-r+1;
        del(l);

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