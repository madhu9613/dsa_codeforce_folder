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
const int MAXN = 3e5 + 5;

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

ll fact[MAXN], invFact[MAXN];
void precompute() {
    fact[0] = 1;
    invFact[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    invFact[MAXN - 1] = modinv(fact[MAXN - 1]);
    for (int i = MAXN - 2; i >= 1; i--) {
        invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
    }
}

ll nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
}

vector<int> primes;
bool isPrime[MAXN];
void sieve(int n) {
    fill(isPrime, isPrime + n + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) isPrime[j] = false;
        }
    }
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) primes.push_back(i);
    }
}

int phi[MAXN];
void sievePhi(int n) {
    for (int i = 0; i <= n; i++) phi[i] = i;
    for (int i = 2; i <= n; i++) {
        if (phi[i] == i) {
            for (int j = i; j <= n; j += i) {
                phi[j] -= phi[j] / i;
            }
        }
    }
}

using Matrix = vector<vector<ll>>;
Matrix matMul(Matrix A, Matrix B) {
    int rA = A.size(), cA = A[0].size(), cB = B[0].size();
    Matrix C(rA, vector<ll>(cB, 0));
    for (int i = 0; i < rA; i++) {
        for (int k = 0; k < cA; k++) {
            for (int j = 0; j < cB; j++) {
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
            }
        }
    }
    return C;
}

Matrix matPow(Matrix A, ll p) {
    int n = A.size();
    Matrix res(n, vector<ll>(n, 0));
    for (int i = 0; i < n; i++) res[i][i] = 1;
    while (p > 0) {
        if (p & 1) res = matMul(res, A);
        A = matMul(A, A);
        p >>= 1;
    }
    return res;
}
vi adj[MAXN];
vi tree_adj[MAXN];
int tin[MAXN],low[MAXN],timer=0;
set<pair<int,int>>bridges;
bool visited[MAXN];
int compid[MAXN];
int cur_comp=0;
// find bridges;
void dfs1(int u,int p=-1){
    visited[u]=true;
    tin[u]=low[u]=++timer;
    for(int v:adj[u]){
        if(v==p)continue;
        if(visited[v]){
            low[u]=min(low[u],tin[v]); 
        }
        else{
            dfs1(v,u);
            low[u]=min(low[u],low[v]);
            if(low[v]>tin[u]){
                // okay bridge;
                bridges.insert({min(u,v),max(u,v)});
            }
        }
    }
}

void build_comp(int u){
    queue<int>q;
    q.push(u);
    compid[u]=cur_comp;
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        for(int v:adj[cur]){
            if(compid[v]==0 && bridges.count({min(cur,v),max(cur,v)})==0){
                compid[v]=cur_comp;
                q.push(v);
            }
        }
    }
}


pair<int,int>bfs_farthest(int s,int n){
    vi dist(n+1,-1);
    queue<int>q;
    q.push(s);
    dist[s]=0;
    int far_node=s;
    int max_dist=0;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int v:tree_adj[u]){
            if(dist[v]==-1){
                dist[v]=dist[u]+1;
                if(dist[v]>max_dist){
                    max_dist=dist[v];
                    far_node=v;
                }
                q.push(v);
            }

        }
    }
    return {far_node,max_dist};
}
void solve() {
    int n,m;cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs1(1);
    for(int i=1;i<=n;i++){
        if(compid[i]==0){
            cur_comp++;
            build_comp(i);
        }
    }
    for(auto edge:bridges){
        int u=edge.first;
        int v=edge.second;
        int comp_u=compid[u];
        int comp_v=compid[v];
        if(comp_u!=comp_v){
            tree_adj[comp_u].push_back(comp_v);
            tree_adj[comp_v].push_back(comp_u);
        }
    }
    pair<int,int>p1=bfs_farthest(1,cur_comp);
    pair<int,int>p2=bfs_farthest(p1.first,cur_comp);
    cout<<p2.second<<endl;
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