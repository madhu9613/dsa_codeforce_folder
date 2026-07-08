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

const int MAXN = 400005 ;
int *where[MAXN*20];
int val[MAXN*20];
int cur=0;


void change(int &x,int y){
    where[cur]=&x;
    val[cur]=x;
    x=y;
    cur++;
}
void rollback(){
    cur--;
    *where[cur]=val[cur];
}

struct DSU{
vi par,sz;
int cnt;
DSU(int n){
    par.resize(n);
    sz.resize(n,1);
    iota(all(par),0);
    cnt=n;
}
int find(int x){
    while(x!=par[x]){
        x=par[x];
    }
    return x;
}
void unite(int a,int b){
    a=find(a);
    b=find(b);
    if(a==b){
        return ;
    }
    if(sz[a]<sz[b]){
        swap(a,b);
    }
    change(par[b],a);
    change(sz[a],sz[a]+sz[b]);
    change(cnt,cnt-1);
}
};

struct edge{
    char type;
    int u,v;
};

vector<edge>seg[4*MAXN];
DSU dsuA(0),dsu_union(0);
int ans[MAXN];

void add (int u,int l,int r,int ql,int qr,edge e){
    if(qr<=l || r<=ql){
        return ;
    }
    if(ql<=l && r<=qr){
        seg[u].push_back(e);
        return ;
    }
    int mid=l+(r-l)/2;
    add(2*u,l,mid,ql,qr,e);
    add(2*u+1,mid,r,ql,qr,e);
}


void dfs(int u,int l,int r){
    int state=cur;
    for(auto &e:seg[u]){
    dsu_union.unite(e.u,e.v);
    if(e.type=='A'){
        dsuA.unite(e.u,e.v);
    }

}
    if(r-l==1){
        ans[l]=dsuA.cnt-dsu_union.cnt;
    }else{
        int mid=l+(r-l)/2;
        dfs(2*u,l,mid);
        dfs(2*u+1,mid,r);
    }
    while(cur>state){
        rollback();

    }

    }




void solve()
{

    int n,q;cin>>n>>q;
    dsuA=DSU(n);
    dsu_union=DSU(n);
    map<pair<int,int>,int>last[2];
    vector<edge> queries(q);
    for(int i=0;i<q;i++){
        char c;
        int u,v;
        cin>>c>>u>>v;
        u--;
        v--;
        if(u>v){
            swap(u,v);
        }
        queries[i]={c,u,v};
        int idx=(c=='A'?0:1);
        if(last[idx].count({u,v})){
            add(1,0,q,last[idx][{u,v}],i,queries[i]);
            last[idx].erase({u,v});
        }else{
            last[idx][{u,v}]=i;
        }
    }
    for(int t=0;t<2;t++){
        for(auto &it:last[t]){
            add(1,0,q,it.second,q,{char('A'+t),it.first.first,it.first.second});
        }
    }

    dfs(1,0,q);
    for(int i=0;i<q;i++){
        cout<<ans[i]<<endl;
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