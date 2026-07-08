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


void solve() {

    int n,m,k;
    cin>>n>>m>>k;

    vector<tuple<int,int,int>>edges(m);
    for(int i=0;i<m;i++){
        int u,v;
        ll w;
        cin>>u>>v>>w;
        edges[i]={w,u,v};
    }

    sort(all(edges));
    int sz=min(m,k);
    edges.resize(sz);

    set<int>unique;
    for(const auto &[w,u,v]:edges){
      
        unique.insert(u);
        unique.insert(v);
    }
    map<int,int>vmap;
    int vcnt=0;
    for(int v:unique){
        vmap[v]=vcnt++;
    }

    vector<vector<pair<int,ll>>>adj(vcnt);
    for (const auto &[w, u, v] : edges)
    {

        int U=vmap[u];
        int V=vmap[v];
        adj[U].push_back({V,w});
        adj[V].push_back({U,w});       
    }
    vll shortest;
    for(int s=0;s<vcnt;s++){
        vll dist(vcnt,INF);
        priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>>pq;
        dist[s]=0;
        pq.push({0,s});
        while(!pq.empty()){
            auto [d,u]=pq.top();
            pq.pop();
            if(d>dist[u]){
                continue;
            }
            for(const auto &edge:adj[u]){
                int v=edge.first;
                ll w=edge.second;
                if(dist[u]+w<dist[v]){
                    dist[v]=dist[u]+w;
                    pq.push({dist[v],v});
                }
            }
        }
// from smaller to larer vertex stored i->j ;j>i;
        for(int i=s+1;i<vcnt;i++){
            if(dist[i]!=INF){
            shortest.push_back(dist[i]);
            }
        }
    }

    sort(all(shortest));
    cout<<shortest[k-1]<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
   // precompute();
   // freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);
    int t = 1;
    while (t--) solve();
    return 0;
}