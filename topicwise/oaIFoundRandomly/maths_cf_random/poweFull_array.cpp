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

int BLOCK_SIZE;

struct query{
int l,r,id;
bool operator<(const query &other) const{
    int me=l/BLOCK_SIZE;
    int you=other.l/BLOCK_SIZE;
    if(me!=you){
        return me<you;
    }
  if(me&1){
    return r<other.r;
  }
  return r>other.r;
}
};
const int MAX_VAL=1e6+5;
ll cnt[MAX_VAL];
ll a[MAXN];
ll ans[MAXN];
ll beauty=0;
inline void add(int x){

    beauty+=(1+2*cnt[x])*x;
    cnt[x]++;

}
inline void remove(int x){
    beauty += (1 - 2 * cnt[x]) * x;
    cnt[x]--;
}

void solve() {
    int n,q;
    cin>>n>>q;
    BLOCK_SIZE=sqrt(n);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    vector<query>queries(q);
    for(int i=0;i<q;i++){
        int l,r;
        cin>>l>>r;
        queries[i]={l,r,i};
    }

    sort(all(queries));
    int L=0,R=0;
    for(const auto &qr:queries){

        while(R<qr.r){
            R++;
            add(a[R]);
        }

        while(R>qr.r){
        remove(a[R]);
        R--;
        }

        while(L<qr.l){
            remove(a[L]);
            L++;
        }

        while(L>qr.l){
            L--;
            add(a[L]);
        }

        ans[qr.id]=beauty;
    }

    for(int i=0;i<q;i++){
        cout<<ans[i]<<endl;
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