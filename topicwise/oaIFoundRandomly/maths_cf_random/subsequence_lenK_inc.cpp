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

// Fast exponentiation (a^b % mod)
ll modpow(ll a, ll b, ll mod = MOD) {
    ll res = 1;
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

// GCD
ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

// LCM
ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

struct segtree{
int n;
vll st;
segtree(int n=0){
    this->n=n;
    st.assign(4*n,0);
}

void update(int node,int l,int r,int idx,ll val){
    if(l==r){
        st[node]+=val;
        return ;
    }
    int mid=(l+r)/2;
    if(idx<=mid){
        update(2*node,l,mid,idx,val);
    }else{
        update(2*node+1,mid+1,r,idx,val);
    }

    st[node]=st[node*2]+st[2*node+1];
}

ll query(int node,int l,int r, int ql,int qr){
    if(qr<l || r<ql){
        return 0;
    }
    if(ql<=l && r<=qr){
        return st[node];
    }
    int mid=(l+r)/2;
    return query(2*node,l,mid,ql,qr)+query(2*node+1,mid+1,r,ql,qr);
}

void update(int idx,ll val){
    update(1,1,n,idx,val);
}
ll query(int l,int r){
    if(l>r){
        return 0;
    }
    return query(1,1,n,l,r);
}
};

void solve() {
    int n,k;cin>>n>>k;
    vi a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];

    }
    vector<segtree>seg(k+2,segtree(n));
    for(int x:a){

        seg[1].update(x,1); //for length 1 starting with x ;
        for(int len=2;len<=k+1;len++){

            ll ways=seg[len-1].query(1,x-1);
            seg[len].update(x,ways);
        }
    }

    cout<<seg[k+1].query(1,n)<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}