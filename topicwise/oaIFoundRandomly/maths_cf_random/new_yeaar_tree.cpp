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
// we need to store bitmasking state in  the tree node it will give 

const int MAXN=4e5+5;
vector<int> adj[MAXN];
int tin[MAXN],tout[MAXN];
int timer=0;
int flat[MAXN]; //the color of nodes;
int a[MAXN]; //given
 
void dfs(int u,int p=-1){
    tin[u]=++timer;
    flat[tin[u]]=a[u];
    for(int v:adj[u]){
        if(v==p) continue;
        dfs(v,u);
    }
    tout[u]=timer;
}

struct segtree{
int n;
vll tree,lazy;


void build(int node,int l,int r){
    if(l==r){
        tree[node]=1LL<<flat[l]; 
        return;
    }
    int mid=(l+r)/2;
    build(2*node,l,mid);
    build(2*node+1,mid+1,r);
    tree[node]=tree[2*node] | tree[2*node+1];
}

segtree(int n){
    this->n=n;
    tree.assign(4*n+5,0);
    lazy.assign(4*n+5,0);
    build(1,1,n);
}


// as we are comp changing the value so
void push(int node){
    if(lazy[node]){
        tree[2*node]=lazy[node];
        lazy[2*node]=lazy[node];

        tree[2 * node+1] = lazy[node];
        lazy[2 * node+1] = lazy[node];

        lazy[node]=0;
    }
}
void update(int node, int l, int r, int ql, int qr, ll cmask)
{
    if (qr < l || r < ql)
    {
        return;
    }

    if (ql <= l && r <= qr)
    {
        tree[node] = cmask;
        lazy[node] = cmask;
        return;
    }
    push(node);
    int mid=(l+r)/2;
    update(2*node,l,mid,ql,qr,cmask);
    update(2*node+1,mid+1,r,ql,qr,cmask);
    tree[node]=tree[2*node] | tree[2*node+1];
}
ll query(int node,int l,int r,int ql,int qr){
    if(qr<l || r<ql){
        return 0LL;
    }
    if(ql<=l && r<=qr){
        return tree[node];
    }
    push(node);
    int mid=(l+r)/2;
    ll left=query(2*node,l,mid,ql,qr);
    ll right=query(2*node+1,mid+1,r,ql,qr);
    return left | right;
}

void update(int l,int r,ll mask){
    update(1,1,n,l,r,mask);
}
ll query(int l,int r){
    return query(1,1,n,l,r);
}
};




void solve() {
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<n;i++){
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);

    }
    dfs(1);
    segtree st(n);
    while(m--){
        int type;cin>>type;
        if(type==1){
            int v,c;cin>>v>>c;
            ll cmask=1LL<<c;
            st.update(tin[v],tout[v],cmask);
        }
        else if(type==2){
            int v;cin>>v;
            ll result=st.query(tin[v],tout[v]);
            cout<<__builtin_popcountll(result)<<endl;
        }
    }
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) solve();

    return 0;
}