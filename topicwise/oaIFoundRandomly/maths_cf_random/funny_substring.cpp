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

struct var{
string pref;
string suff;
ll cnt ;
};
ll count_haha(const string &s){
    ll c=0;
    if(s.length()<4){
        return 0;
    }
    // n=10
    // 0 1 2 3 4 5 6 7 8 9
    //i ==10-4=6

    for(size_t i=0;i<=s.length()-4;i++){
        if(s.substr(i,4)=="haha"){
            c++;
        }
    }
    return c;
}
void solve() {
    int n;
    cin>>n;
    map<string,var>Vars;
    string last;
    for(int i=0;i<n;i++){
        string x,op;
        cin>>x>>op;
        last=x;
        if(op==":="){
            string s;
            cin>>s;
            var v;
            v.cnt=count_haha(s);
            v.pref=s.length()>=3?s.substr(0,3):s;
            v.suff=s.length()>=3?s.substr(s.length()-3):s;
            Vars[x]=v;
        }
        else{
            string a,plus,b;
            cin>>a>>plus>>b;
            var va=Vars[a];
            var vb=Vars[b];
            var vc;
            vc.cnt=va.cnt+vb.cnt+count_haha(va.suff+vb.pref);
            string npref=va.pref+vb.pref;
            vc.pref=npref.length()>=3?npref.substr(0,3):npref;

            string nsuff=va.suff+vb.suff;
            vc.suff=nsuff.length()>=3?nsuff.substr(nsuff.length()-3):nsuff;

            Vars[x]=vc;
        }
    }

    cout<<Vars[last].cnt<<endl;
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