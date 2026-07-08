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
const int MAXN = 1e5 + 5;

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
const int LOG=20;
int n,Q;
vector<pair<int,ll>>adj[MAXN];
int deg[MAXN];
int up[MAXN][LOG];
int depth[MAXN];
int root[MAXN];
int in_cycle[MAXN];
ll dist[MAXN];
ll cdist[MAXN];

void dfs(int u,int p,int r,ll cost,int d){
    root[u]=r;
    dist[u]=cost;
    depth[u]=d;
    up[u][0]=p; // direct parent;
    for(int i=1;i<LOG;i++){
        up[u][i]=up[up[u][i-1]][i-1];
    }
    for(auto &[v,w]:adj[u]){
        if(v!=p && !in_cycle[v]){
            dfs(v,u,r,cost+w,d+1);
        }
    }
}

int get_lca(int u,int v){
    if(depth[u]<depth[v]){
        swap(u,v);
    }
    for(int i=LOG-1;i>=0;i--){
        if(depth[u]-(1<<i)>=depth[v]){
            u=up[u][i];
        }
    }
    if(u==v){
        return u;
    }
    for(int i=LOG-1;i>=0;i--){
        if(up[u][i]!=up[v][i]){
            u=up[u][i];
            v=up[v][i];
        }
    }
    return up[u][0];
}

void solve() {
   
    cin>>n>>Q;
    for (int i = 0; i <= n; i++)
    {
        adj[i].clear();
        deg[i] = 0;
    }
    for(int i=0;i<n;i++){
        int u,v;
        ll w;cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
        deg[u]++;
        deg[v]++;
    }
    queue<int>q;
    for(int i=1;i<=n;i++){
        if(deg[i]==1){
            q.push(i);
        }
    }
    memset(in_cycle,1,sizeof(in_cycle));
    while(!q.empty()){
        int u=q.front();
        q.pop();
        in_cycle[u]=0;
        for(auto &[v,w]:adj[u]){
            if(--deg[v]==1){
                q.push(v);
            }
        }
    }

    int start=0;

    for(int i=1;i<=n;i++){
        if(in_cycle[i]){
            if(!start){
                start=i;
            }
            dfs(i,0,i,0,0);
        }
    }


    ll cycle_len=0;
    int cur=start;
    int prev=0;
    ll d=0;
    while(true){
        cdist[cur]=d;
        int nxt_node=0;
        ll edge_w=0;
        for(auto &[v,w]:adj[cur]){
            if(in_cycle[v] && v!=prev){
                nxt_node=v;
                edge_w=w;
                break;
            }
        }
        if(nxt_node==start){
            cycle_len=d+edge_w;
            break;
        }
        d+=edge_w;
        prev=cur;
        cur=nxt_node;
    }
    
    while(Q--){
        int u,v;cin>>u>>v;
        if(root[u]==root[v]){
            int lca=get_lca(u,v);
            ll ans=dist[u]+dist[v]-2LL*dist[lca];
            cout<<ans<<endl;
        }else{
            ll base=dist[u]+dist[v];
            ll cd1=cdist[root[u]];
            ll cd2=cdist[root[v]];

            ll diff=abs(cd1-cd2);
            ll shorted_cycle=min(diff,cycle_len-diff);
            cout<<base+shorted_cycle<<endl;
        }
    }
   

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
   // precompute();
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}