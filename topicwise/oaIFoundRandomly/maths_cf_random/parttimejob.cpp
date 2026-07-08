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

const int MAXN=2e5+5;
vector<int>adj[MAXN];
int tin[MAXN];
int tout[MAXN];
int flat[MAXN];
int a[MAXN];
int timer=0;
int n,q;

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
// int tree[4*MAXN];
// int lazy[4*MAXN];

vi tree,lazy;
int n;

segtree(int n){
    this->n=n;
    tree.assign(4*n+5,0);
    lazy.assign(4*n+5,0);
    build(1,1,n);

}
void build(int node, int l, int r)
{
    if (l == r)
    {
        tree[node] = flat[l];
        return;
    }
    int mid = (l + r) / 2;
    build(2 * node, l, mid);
    build(2 * node + 1, mid + 1, r);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

void push(int node,int l,int r){
    if(lazy[node]){
        int mid=(l+r)/2;
        tree[2*node]=(mid-l+1)-tree[2*node];
        lazy[2*node]^=1;

        tree[2*node+1]=(r-mid)-tree[2*node+1];
        lazy[2*node+1]^=1;

        lazy[node]=0;
    }
}

void update(int node,int l,int r,int ql,int qr){
    if(qr<l || r<ql){
        return ;
    }
    if(ql<=l && r<=qr){
        tree[node]=(r-l+1)-tree[node];
        lazy[node]^=1;
        return;
    }

    push(node,l,r);
    int mid=(l+r)/2;
    update(2*node,l,mid,ql,qr);
    update(2*node+1,mid+1,r,ql,qr);

    tree[node]=tree[2*node]+tree[2*node+1];
}

void update(int l,int r){
    update(1,1,n,l,r);
}

int query(int node,int l,int r,int ql,int qr){
    if(qr<l || r<ql){
        return 0;
    }
    if(ql<=l && r<=qr){
        return tree[node];
    }
    push(node,l,r);
    int mid=(l+r)/2;
    int p1=query(2*node,l,mid,ql,qr);
    int p2=query(2*node+1,mid+1,r,ql,qr);
    return p1+p2;
}

int query(int ql,int qr){
   return query(1,1,n,ql,qr);
}

};

void solve() {

    cin>>n;
    for(int i=2;i<=n;i++){
        int p;cin>>p;
        adj[p].push_back(i);
        adj[i].push_back(p);
    }
    
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dfs(1);
    segtree st(n);
    cin>>q;
    while(q--){
        string type;
        int v;
        cin>>type>>v;
        if(type=="get"){
            cout<<st.query(tin[v],tout[v])<<endl;
        }else if(type=="pow"){
            st.update(tin[v],tout[v]);
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