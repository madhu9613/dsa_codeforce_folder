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

ll inversions=0;
int n;
ll k;
struct Fenwick{
int sz;
vi tree;
Fenwick(int n):sz(n),tree(n+1,0) {}

void add(int i,int delta){
    for(;i<=sz;i+=i&-i){
        tree[i]+=delta;
    }
}

int query(int i){
    int sum=0;
    for(;i>0;i-=i&-i){
        sum+=tree[i];
    }
    return sum;
}
int query_range(int l,int r){
    if(l>r){
        return 0;
    }
    return query(r)-query(l-1);
}
};
void solve() {

    cin>>n>>k;
    vi a(n+1);
    vi vals;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        vals.push_back(a[i]);

    }
    sort(all(vals));
    vals.erase(unique(all(vals)),vals.end());
    for(int i=1;i<=n;i++){
        a[i]=lower_bound(all(vals),a[i])-vals.begin()+1;
    }


    int m=vals.size();
    Fenwick bit_left(m),bit_right(m);
    // l=0; i mean [1..n] in suffix;
    for(int i=1;i<=n;i++){
        inversions+=bit_right.query_range(a[i]+1,m);// larger value than x=a[i];
        bit_right.add(a[i],1);
    }
    ll ans=0;
    int r=1;
    for(int l=1;l<=n;l++){
        //add a[l] to left BIT;
      inversions+=bit_left.query_range(a[l]+1,m);  // number larger than a[l]
      inversions+=bit_right.query(a[l]-1); // number less than a[l];
      bit_left.add(a[l],1);
      // inversion become larger remove from suffix;
      while(r<=n && (r<=l || inversions>k)){

        //[1...l]U[r..n] let say i remove a[r]; larger element int left or smaller element in right must sub;
        inversions-=bit_left.query_range(a[r]+1,m);
        inversions-=bit_right.query(a[r]-1);
        bit_right.add(a[r],-1);
        r++;
      }

      if(r<=n){
        ans+=(n-r+1);
      }

    }

    cout<<ans<<endl;


    
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