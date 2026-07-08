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
struct DSU {
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n + 1);
        size.assign(n + 1, 1);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int v) {
        if (v == parent[v]) return v;
        return parent[v] = find(parent[v]);
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            if (size[a] < size[b]) swap(a, b);
            parent[b] = a;
            size[a] += size[b];
            return true;
        }
        return false;
    }
};

int n,m;
vector<vi>adj;
vi tin;
vi tout;
struct event{
int type,x,y;
};

struct query{
int emp;
int qid;
};
int timer=0;
void dfs(int u){
tin[u]=++timer;
for(int v:adj[u]){
   
    dfs(v);
}
tout[u]=++timer;
}

bool is_ancestor(int u,int v){
    return tin[u]<=tin[v] && tout[v]<=tout[u];
}
void solve() {
    cin>>n>>m;
    adj.resize(n+1);
    tin.assign(n+1,0);
    tout.assign(n+1,0);
    vector<event>events(m);
    vi boss(n+1,0);
    vector<vector<query>>doc_query(m+1);
    int doc_cnt=0;
    DSU dsu(n);
    int type3=0;
    for(int i=0;i<m;i++){
        int t;cin>>t;
        if(t==1){
            int x,y;
            cin >> x >> y;
            events[i] = {t, x, y};
            adj[y].push_back(x);
            boss[x] = y;
        }
        else if(t==2){
            int x;cin>>x;
            events[i]={t,x,-1};
            doc_cnt++;
        }
        else{
            int x,y;
            cin>>x>>y;
            events[i]={t,x,y};
            doc_query[y].push_back({x,type3++});
        }
    }

    for(int i=1;i<=n;i++){
        if(boss[i]==0){
            dfs(i);
        }
    }
    

    vi Doc(m+1);  
    vector<bool>ans(type3);
    int cur_doc=0;

    int type2=0;
    for(int i=0;i<m;i++){

        int t=events[i].type;
        int x=events[i].x;
        int y=events[i].y;
        if(t==1)
        {
            dsu.unite(x,y);
        }
        else if(t==2){
           cur_doc++;
           int owner=x;
           for(auto &q:doc_query[cur_doc]){
            if(is_ancestor(q.emp,owner) && dsu.find(q.emp)==dsu.find(owner)){
                ans[q.qid]=true;
            }else{
                ans[q.qid]=false;
            }
           }
        }
      
    }

    for(int i=0;i<type3;i++){
        if(ans[i]){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }


    

    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
   // precompute();
    int t = 1;
    while (t--) solve();
    return 0;
}