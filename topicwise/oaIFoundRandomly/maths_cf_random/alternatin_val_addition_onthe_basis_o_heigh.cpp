#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
#define vi vector<int>
#define vll vector<ll>
#define vpi vector<pii>
#define vpll vector<pll>

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

const ll INF = 1e18;
const int MOD = 1000000007;

// Fast exponentiation (a^b % mod)
ll modpow(ll a, ll b, ll mod = MOD) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

ll modinv(ll a, ll mod = MOD) {
    return modpow(a, mod - 2, mod);
}

// GCD
ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

// LCM
ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}
// if dmod2 same as x it will be +val and is diff -val;
// we can maintin 2 diff segment ;
const int MAXN=2e5+5;
vi adj[MAXN];
int tin[MAXN],tout[MAXN],depth[MAXN];
int timer=0;
int n,m;
int a[MAXN];
void dfs(int u,int p=-1,int d=0){
    tin[u]=++timer;
    depth[u]=d%2;
    for(int v:adj[u]){
        if(v==p) continue;
        dfs(v,u,d+1);
    }
    tout[u]=timer;
}

// we just need point query so donot care about any range;so keeoing it simple;

struct segtree{
int n;
vll tree;
segtree(int n){
    this->n=n;
    tree.assign(4*n+5,0);
}

void update(int node, int l, int r, int ql, int qr, ll val)
{
    if (qr < l || r < ql)
        return;

    if (ql <= l && r <= qr)
    {
        tree[node] += val; 
        return;
    }

    int mid = (l + r) / 2;
    update(2 * node, l, mid, ql, qr, val);
    update(2 * node + 1, mid + 1, r, ql, qr, val);
}
ll query(int node, int l, int r, int pos)
{
    if (l == r)
    {
        return tree[node];
    }

    int mid = (l + r) / 2;
    ll res = tree[node];

    if (pos <= mid)
    {
        res += query(2 * node, l, mid, pos);
    }
    else
    {
        res += query(2 * node + 1, mid + 1, r, pos);
    }
    return res;
}


void update(int l,int r,ll val){
    update(1,1,n,l,r,val);
}

ll query(int pos){
    return  query(1,1,n,pos);
}
};

void solve() {
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<n;i++){

        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    segtree st[2]={segtree(n),segtree(n)};
    while(m--){
        int type;cin>>type;
        if(type==1)
        {
            int x;ll val;cin>>x>>val;
            int p=depth[x];
            st[p].update(tin[x],tout[x],val);
            st[1-p].update(tin[x],tout[x],-val);
        }else if(type==2){
            int x;cin>>x;
            int p=depth[x];
            ll cval=a[x]+st[p].query(tin[x]);

            cout<<cval<<endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}