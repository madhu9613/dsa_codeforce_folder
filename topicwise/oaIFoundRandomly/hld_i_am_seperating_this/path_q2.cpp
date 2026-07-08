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
const int MAXN = 2e5 + 5;

ll modpow(ll a, ll b, ll mod = MOD) {
    ll res = 1;
    a %= mod;
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

ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}



int n,q;
vi adj[MAXN];
int vals[MAXN];

int par[MAXN],depth[MAXN],heavy[MAXN],head[MAXN],pos[MAXN];
int cpos=1;
int flat[MAXN];

struct segtree{
int n;
vi tree;
segtree(int n)
{
    this->n=n;
    tree.resize(2*n+3);
    build();
}
void build(){
 for(int i=0;i<n;i++){
    tree[n+i]=flat[i+1];
 }

 for(int i=n-1;i>0;i--){
     tree[i]=max(tree[i<<1],tree[i<<1|1]);
 }
}
void update(int idx,int val){
    idx--; // zero;
    for(tree[idx+=n]=val;idx>1;idx>>=1){
        tree[idx>>1]=max(tree[idx],tree[idx^1]);
    }
}
int query(int l, int r)
{
    l--;
    r--;

    int res = INT_MIN;

    for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1)
    {

        if (l & 1)
            res = max(res, tree[l++]);

        if (r & 1)
            res = max(res, tree[--r]);
    }

    return res;
}
};
int dfs1(int u,int p){
    int sz=1;
    int max_child=0;
    heavy[u]=-1; // no heacvy child yet;
    for(int v:adj[u]){
        if(v==p) continue;

        par[v]=u;
        depth[v]=depth[u]+1;
        int child=dfs1(v,u);
        sz+=child;
        if(child>max_child){
            max_child=child;
            heavy[u]=v;

        }
    }
    return sz;
}


void decompose(int u,int p,int h){
    head[u]=h;
    pos[u]=cpos;
    flat[cpos]=vals[u];
    cpos++;
    if(heavy[u]!=-1){

        decompose(heavy[u],u,h);
    }

    for(int v:adj[u])
    {
        if(v==p || v==heavy[u]) continue;
        decompose(v,u,v);
    }
}

int path_query(int a,int b,segtree &st){
    int res=0;
    while(head[a]!=head[b]){
        if(depth[head[a]]<depth[head[b]]){
            swap(a,b);
        }
        res=max(res,st.query(pos[head[a]],pos[a]));
        a=par[head[a]];
    }
    if(depth[a]>depth[b]){
        swap(a,b);
    }
    res=max(res,st.query(pos[a],pos[b]));
    return res;
}
void solve() {
    cin>>n>>q;

    for(int i=1;i<=n;i++)
    {
        cin>>vals[i];
    }

    for(int i=0;i<n-1;i++){
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    depth[1]=0;
    par[1]=0;

    dfs1(1,0);
    cpos=1;
    decompose(1,0,1);
    segtree st(n);
    for(int i=0;i<q;i++){
        int t;cin>>t;
        if(t==1){
            int s,x;
            cin>>s>>x;
            vals[s]=x;
        st.update(pos[s],x);
        }else if(t==2){
            int a,b;
            cin>>a>>b;
            cout<<path_query(a,b,st)<<" ";
        }
    }
    cout<<endl;
   

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
   // precompute();
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}