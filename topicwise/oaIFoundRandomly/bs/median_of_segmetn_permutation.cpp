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

void solve() {
int n,m;
cin>>n>>m;
int pos=0;
vi p(n);
for(int i=0;i<n;i++){
    cin>>p[i];
    if(p[i]==m){
        pos=i;
    }
}    
int csum=0;
unordered_map<ll,int>right;
for(int r=pos;r<n;r++){
    if(p[r]<m){
        csum--;
    }
    else if(p[r]>m){
        csum++;
    }
    right[csum]++;
}

ll cnt=0;
csum=0;
for(int l=pos;l>=0;l--){

     if(p[l]>m){
        csum++;
     }
     else if(p[l]<m){
        csum--;
     }

    //  sl+sr=0 or 1;
    ll t0=-csum;
    if(right.count(t0)){
        cnt+=right[t0];
    }

    ll t1=1-csum;
    if(right.count(t1)){
        cnt+=right[t1];
    }
}

cout<<cnt<<endl;

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