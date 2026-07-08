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



void solve() {
    int n,q;cin>>n>>q;

    set<int>pos;
    multiset<int>gaps;
    auto remove=[&](int x){
 gaps.erase(gaps.find(x));
    };

    auto add_pile=[&](int x){

        auto it=pos.insert(x).first;
        auto prev_it=it,nxt_it=it;
        bool has_prev=(it!=pos.begin());
        bool has_nxt=false;

        nxt_it++;
        if(nxt_it!=pos.end()){
            has_nxt=true;
        }
        if(has_prev){
            prev_it--;
        }

        if(has_prev && has_nxt){
            remove(*nxt_it-*prev_it);
        }

        if(has_prev){
            gaps.insert(x-*prev_it);
        }

        if(has_nxt){
            gaps.insert(*nxt_it-x);
        }

    };

    auto remove_pile=[&](int x){
        auto it=pos.find(x);
        auto prev_it=it,nxt_it=it;
        bool has_prev=(it!=pos.begin());

        bool has_nxt=false;
        nxt_it++;
        if(nxt_it!=pos.end()){
            has_nxt=true;
        }
        if(has_prev){
            prev_it--;
        }

        if(has_prev){
            remove(x-*prev_it);
        }
        if(has_nxt){
            remove(*nxt_it-x);
        }

        if(has_prev && has_nxt){
            gaps.insert(*nxt_it-*prev_it);
        }

        pos.erase(it);

    };

    auto ans=[&]{

        if (pos.size() <= 2)
        {
            cout << 0 << endl;
            return;
        }
        else
        {
            int max_pos = *pos.rbegin();
            int min_pos = *pos.begin();
            int max_gap = *gaps.rbegin();
            cout << (max_pos - min_pos) - max_gap << endl;
        }
    };
    for(int i=0;i<n;i++){
        int p;
        cin>>p;
        add_pile(p);
    }


     ans();
     while(q--){
        int t,x;cin>>t>>x;
        if(t==0){
            remove_pile(x);
        }
        else{
            add_pile(x);
        }

        ans();
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