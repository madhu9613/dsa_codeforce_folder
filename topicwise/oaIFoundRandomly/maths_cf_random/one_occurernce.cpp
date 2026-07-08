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

const ll INF = 1e8;
const int MOD = 1000000007;
const int MAXN = 5e5 + 5;

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

vector<pair<int,int>>tree;
void build(int node,int l,int r){
    if(l==r){
        tree[node]={INF,l};
        return;
    }

    int mid=(l+r)/2;
    build(2*node,l,mid);
    build(2*node+1,mid+1,r);
    tree[node]=min(tree[2*node],tree[2*node+1]);
}

void update(int node,int l,int r,int idx,int val){
    if(l==r){
        tree[node]={val,idx};
        return;
    }
    int mid=(l+r)/2;
    if(idx<=mid){
        update(2*node,l,mid,idx,val);
    }else{
        update(2*node+1,mid+1,r,idx,val);
    }
tree[node]=min(tree[2*node],tree[2*node+1]);
}

pair<int,int> query(int node,int l,int r,int ql,int qr){
    if(qr<l || r<ql){
        return {INF,-1};
    }
    if(ql<=l && r<=qr){
        return tree[node];
    }
    int mid=(l+r)/2;
    return min(query(2*node,l,mid,ql,qr),query(2*node+1,mid+1,r,ql,qr));
}
void solve() {
    int n;cin>>n;
    vi a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int q;
    cin>>q;
    vector<vector<pair<int,int>>>queries(n+1);
    for(int i=0;i<q;i++){
        int l,r;
        cin>>l>>r;
        queries[r].push_back({l,i});
    }
    unordered_map<int,int>last;

    tree.resize(4*n+5);
    build(1,1,n);

   vi ans(q);
    for(int i=1;i<=n;i++){
        int prev=last.count(a[i])?last[a[i]]:0;

        if(prev){
            update(1, 1, n, prev, INF);
        }
       
        update(1,1,n,i,last[a[i]]);
        last[a[i]] = i;

        for(auto q:queries[i]){

            auto res=query(1,1,n,q.first,i);
            if(res.first>=q.first){
                ans[q.second]=0;
            }else{
                ans[q.second]=a[res.second];
            }

        }

    }
    for(int i=0;i<q;i++){
        cout<<ans[i]<<endl;
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