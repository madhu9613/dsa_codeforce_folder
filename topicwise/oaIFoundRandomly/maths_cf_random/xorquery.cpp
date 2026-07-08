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
const int MAX_VAL=1<<20;
int BLOCK_SIZE;

struct query{
int l,r,id;
bool operator<(const query &other){
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
int cnt[MAX_VAL];
ll c_ans=0;
int k;

inline void add(int x){

    c_ans+=cnt[x^k];
    cnt[x]++;

}

inline void remove(int x){
    cnt[x]--;
    c_ans-=cnt[x^k];
}

void solve() {

    int n,m;
    cin>>n>>m>>k;
    BLOCK_SIZE=sqrt(n);
    vi a(n+1);
    vi p(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        p[i]=p[i-1]^a[i];
    }
    vector<query>queries(m);
    for(int i=0;i<m;i++){
        int l,r;
        cin>>l>>r;
        queries[i]={l-1,r,i};
    }
    sort(all(queries));
    vll ans(m);
    int L=0,R=-1;
    for(const auto &q:queries){
        while (L > q.l)
        {
            L--;
            add(p[L]);
        }

        while (R < q.r)
        {
            R++;
            add(p[R]);
        }

        while (L < q.l)
        {
            remove(p[L]);
            L++;
        }

        while (R > q.r)
        {
            remove(p[R]);
            R--;
        }

        ans[q.id]=c_ans;
    }

    for(int i=0;i<m;i++){
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