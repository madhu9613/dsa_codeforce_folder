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

struct segtree
{
    int n;
    vll tree;
    segtree(int n) : n(n), tree(4 * n, 0) {}

    void update(int node, int l, int r, int pos, ll val)
    {
        if (l == r)
        {
            tree[node] = (tree[node]+val)%MOD;
            return;
        }
        int mid = l + (r - l) / 2;
        if (pos <= mid)
        {
            update(2 * node, l, mid, pos, val);
        }
        else
        {
            update(2 * node + 1, mid + 1, r, pos, val);
        }
        tree[node] = (tree[2 * node]+ tree[2 * node + 1]);
    }
    ll query(int node, int l, int r, int ql, int qr)
    {
        if (qr < l || r < ql)
            return 0;
        if (ql <= l && r <= qr)
            return tree[node];
        int mid = l + (r - l) / 2;
        return (
            query(2 * node, l, mid, ql, qr)+
            query(2 * node + 1, mid + 1, r, ql, qr));
    }
};
void solve() {
    //dp[i]=# of inc subseq ending at idx i;
    // dp[i]=1+sigma(dp[j]) j<i where a[j]<a[i]

    int n;cin>>n;
    vll a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    vll vals=a;
    sort(all(vals));
    vals.erase(unique(all(vals)),vals.end());

    int m=vals.size();
    segtree seg(m);
    ll ans=0;

    auto get = [&](ll x) -> int
    {
        return int(lower_bound(all(vals), x) - vals.begin()) + 1;
    };
    for(int i=0;i<n;i++)
    {

        int pos=get(a[i]);
        ll ways=seg.query(1,1,m,1,pos-1);
        ll dp=(ways+1)%MOD;
        seg.update(1,1,m,pos,dp);
        ans=(ans+dp)%MOD;

    }
    cout<<ans<<endl;
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