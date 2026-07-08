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
const int MAXN=1e5+5;
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
int depth[MAXN];
int par[MAXN];
int n,m,k;
int mincycle;
int s=-1;
int e=-1;

void dfs(int u,int p=-1,int d=1){

    depth[u]=d;
    par[u]=p;
    for(int v:adj[u]){
        if(v==p) continue;
        if(depth[v]!=0){
            if(depth[u]>depth[v]){
                int len=depth[u]-depth[v]+1;
                if(len<mincycle){
                    mincycle=len;
                    e=u;
                    s=v;
                }
            }
        }else{
            dfs(v,u,d+1);
        }
    }
}

void solve() {
    cin>>n>>m>>k;
    for(int i=0;i<m;i++){
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    mincycle=n+4;

    dfs(1);
    int size=(k+1)/2;
    if(mincycle<=k){
        // we find the cycle;
        vi cycle;
        int i=e;
        while(i!=s){
            cycle.push_back(i);
            i=par[i];
        }
        cycle.push_back(s);

        cout<<2<<endl;
        cout<<cycle.size()<<endl;
        for(int i=0;i<cycle.size();i++){
            cout<<cycle[i]<<" ";
        }cout<<endl;
    }else if(mincycle!=n+4){
        // we got the cycle but its not the <=k
        vi cycle;
        int i=e;
        while(i!=s){
            cycle.push_back(i);
            i=par[i];
        }
        cycle.push_back(s);
        vi iset;
        int N=cycle.size();
        int s=0;
        i=0;
        while(s<size){
            iset.push_back(cycle[i]);
            i+=2;
            s++;
        }

        cout<<1<<endl;
        N=iset.size();
        for(int i=0;i<N;i++){
            cout<<iset[i]<<" ";
        }
        cout<<endl;
    }else{
        vi even;
        vi odd;
        for(int i=1;i<=n;i++){
            if(depth[i]%2==0){
                even.push_back(i);
            }else{
                odd.push_back(i);
            }
        }

        cout<<1<<endl;
        if(even.size()>=size)
        {
            for(int i=0;i<size;i++){
                cout<<even[i]<<" ";
            }
            cout<<endl;
        }else{
            for(int i=0;i<size;i++){
                cout<<odd[i]<<" ";
            }
            cout<<endl;
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