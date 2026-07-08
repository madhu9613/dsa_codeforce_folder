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
const int MAXN=1e5+5;
vi adj[MAXN];
int tin[MAXN],tout[MAXN];
int timer=0;
vector<pair<int,int>>events[MAXN];
int ans[MAXN];

void dfs1(int u,int p=-1){
    tin[u]=++timer;
    for(int v:adj[u]){
        if(v!=p){
            dfs1(v,u);
        }
    }
    tout[u]=timer;
}

struct segtree{
int n;
vi minval,mincnt,lazy;
segtree(int n){
    this->n=n;
    minval.assign(4*n+5,0);
    mincnt.assign(4*n+5,0);
    lazy.assign(4*n+5,0);
    build(1,1,n);
}
void build(int node,int l,int r){
    minval[node]=0;
    mincnt[node]=1; // count of no of zeros;
    if(l==r){
        return;
    }
    int mid=(l+r)/2;
    build(2*node,l,mid);
    build(2*node+1,mid+1,r);
    pull(node);
}

void push(int node){

    if(lazy[node]){
        int val = lazy[node];
        minval[2 * node] += val;
        lazy[2*node]+=val;

        minval[2 * node+1] += val;
        lazy[2 * node+1] += val;

        lazy[node]=0;
    }
}

void pull(int node){
    minval[node]=min(minval[2*node],minval[2*node+1]);
    mincnt[node]=0;
    if(minval[node]==minval[2*node]){
        mincnt[node]+=mincnt[2*node];
    }
    if(minval[node]==minval[2*node+1]){
        mincnt[node]+=mincnt[2*node+1];
    }
}

void update(int node,int l,int r,int ql,int qr,int val){
    if(qr<l || r<ql){
        return;
    }

    if(ql<=l && r<=qr){
        minval[node]+=val;
        lazy[node]+=val;
        return ;
        
    }
    push(node);
    int mid=(l+r)/2;
    update(2*node,l,mid,ql,qr,val);
    update(2*node+1,mid+1,r,ql,qr,val);
    pull(node); // merge step;
}

int getcov(){
    if(minval[1]==0){
        return n-mincnt[1];
    }
    return n; // all are covered;
}

void update(int l,int r,int val){
    update(1,1,n,l,r,val);
}
};

void dfs2(int u,int p,segtree &st){
    for(auto &ev:events[u]){
        st.update(ev.first,ev.second,1); 
    }

    int coverd=st.getcov();
    if(coverd>0){

        ans[u]=coverd-1;
    }else{
        ans[u]=0;
    }

    for(int v:adj[u]){
        if(v==p) continue;
        dfs2(v,u,st);
    }

    for(auto &e:events[u]){
        st.update(e.first,e.second,-1); // backtrack
    }


}
void solve() {

    int n,m;cin>>n>>m;
    for(int i=1;i<n;i++){
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs1(1);
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        events[a].push_back({tin[a],tout[a]});
        events[a].push_back({tin[b],tout[b]});

        events[b].push_back({tin[a], tout[a]});
        events[b].push_back({tin[b], tout[b]});
    }

    segtree st(n);
    dfs2(1,0,st);

    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}