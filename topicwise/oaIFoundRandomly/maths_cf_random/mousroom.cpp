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

vector<vector<pair<int,ll>>>adj,rev_adj;
vector<bool>visited;
vi order;
int n,m;
vi sccid;
vll sccval;
vector<vector<pair<int,ll>>>scc_graph;

ll get_val(ll x)
{
    ll m = (sqrt(8.0 * x + 1) - 1.0) / 2.0;
    while (m * (m + 1) / 2 > x)
    {
        m--;
    }
    while ((m + 1) * (m + 2) / 2 <= x)
    {
        m++;
    }
    return x * (m + 1) - (m) * (m + 1) * (m + 2) / 6;
}
void dfs1(int u){
    visited[u]=true;
    for(auto &[v,w]:adj[u]){
        if(!visited[v]){
            dfs1(v);
        }
    }
    order.push_back(u);
}
// assign scc id;

void dfs2(int u,int id){
    sccid[u]=id;
    for(auto &[v,w]:rev_adj[u]){
        if(sccid[v]==-1){
            dfs2(v,id);
        }
    }
}

void solve() {
cin>>n>>m;
adj.resize(n+1);
rev_adj.resize(n+1);
visited.resize(n+1,false);

for(int i=0;i<m;i++){
    int u,v;
    ll w;cin>>u>>v>>w;
    adj[u].push_back({v,w});
    rev_adj[v].push_back({u,w});
}
int s;cin>>s;
for(int i=1;i<=n;i++){
    if(!visited[i]){
        dfs1(i);
    }
}

reverse(all(order));
sccid.resize(n+1,-1);
int id=1;
for(auto &u:order){
    if(sccid[u]==-1){
        dfs2(u,id++);
    }
}

sccval.resize(id,0);
scc_graph.resize(id);

vi indeg(id,0);
for(int u=1;u<=n;u++){
    for(auto &[v,w]:adj[u]){
        int sccu=sccid[u];
        int sccv=sccid[v];
        if(sccu==sccv){
            sccval[sccu]+=get_val(w);
        }else{
            scc_graph[sccu].push_back({sccv,w});
            indeg[sccv]++;
        }
    }
}

vll dp(id,-1);
queue<int>q;
for(int u=1;u<id;u++){
    if(indeg[u]==0){
        q.push(u);
    }
}

dp[sccid[s]]=sccval[sccid[s]];
ll ans=0;
while(!q.empty()){
    int u=q.front();
    q.pop();
    ans=max(ans,dp[u]); 
    for(auto &[v,w]:scc_graph[u]){
        if(dp[u]!=-1){
            dp[v]=max(dp[v],dp[u]+w+sccval[v]);
        }
        if(--indeg[v]==0){
            q.push(v);
        }
    }
}
cout<<ans<<endl;


    
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