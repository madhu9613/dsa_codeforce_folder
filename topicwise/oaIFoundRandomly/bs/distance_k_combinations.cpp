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

struct edge{
int to;
int id;
};
int n,m,k;
vector<vector<edge>>adj;
vector<int>dist;
vector<vector<int>>valid_edges;
vector<string>ans;
string cans;

void f(int u){
    if(ans.size()==k) return ;
    if(u==n+1){
        ans.push_back(cans);
        return;
    }
    for(int edge_id:valid_edges[u]){
        cans[edge_id]='1';
        f(u+1);
        cans[edge_id]='0';
    }
}

void solve() {
    cin>>n>>m>>k;
    adj.resize(n+1);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back({v,i});
        adj[v].push_back({u,i});
    }

    dist.assign(n+1,-1);
    queue<int>q;
    dist[1]=0;
    q.push(1);
    dist[1]=0;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(const auto &edge:adj[u]){
            if(dist[edge.to]==-1){
                dist[edge.to]=dist[u]+1;
                q.push(edge.to);
            }
        }
    }

    valid_edges.resize(n+1);
    for(int u=1;u<=n;u++){
        for(auto &edge:adj[u]){
            if(dist[u]+1==dist[edge.to]){
                // u->to its a valid so 
                valid_edges[edge.to].push_back(edge.id);
            }
        }
    }

    cans=string(m,'0');
    f(2);
    cout<<ans.size()<<endl;
    for(string &a:ans)
    {
        cout<<a<<endl;
    }
    
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