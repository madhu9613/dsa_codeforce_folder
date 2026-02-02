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
struct segtree{
int n;
vi tree;
segtree(int n) :n(n) {
    tree.assign(4*n,0);
}
void clear()
{
    fill(all(tree),0);
}
void update(int node,int l,int r,int pos,int val)
{
    if(l==r)
    {
        tree[node]+=val;
        return ;
    }
    int mid=l+(r-l)/2;
    if(pos<=mid)
    {
        update(2*node,l,mid,pos,val);
    }else{
        update(2*node+1,mid+1,r,pos,val);
    }
    tree[node]=tree[2*node]+tree[2*node+1];
}

int query(int node, int l, int r, int ql, int qr)
{
    if (qr < l || ql > r) 
        return 0;

    if (ql <= l && r <= qr) 
        return tree[node];

    int mid = l + (r - l) / 2;
    return query(2 * node, l, mid, ql, qr) + query(2 * node + 1, mid + 1, r, ql, qr);
}

void add(int pos,int val)
{
    update(1,1,n,pos,val);
}
int range_sum(int l,int r)
{
    if(l>r) return 0;
    return query(1,1,n,l,r);
}
};

void solve()
{
    int n;
    cin >> n;
    vi a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i]++;
    }

    segtree st0(n);
    ll inv0 = 0;
    for (int i = 1; i <= n; i++)
    {
        inv0 += st0.range_sum(a[i] + 1, n);
        st0.add(a[i], 1);
    }

    ll best = inv0;
    ll ways = 0;

    segtree st(n);
    for (int i = 1; i <= n; i++)
    {
        st.clear();
        for (int j = i + 1; j <= n; j++)
        {
            st.add(a[j - 1], 1);

            if (a[i] <= a[j])
                continue;

            int x = a[i];
            int y = a[j];

            int cnt = st.range_sum(y + 1, x - 1);
            ll ninv = inv0 - 1 - 2LL * cnt;

            if (ninv < best)
            {
                best = ninv;
                ways = 1;
            }
            else if (ninv == best)
            {
                ways++;
            }
        }
    }

    cout << best << " " << ways << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    // cin>>t;
    while (t--)
        solve();

    return 0;
}