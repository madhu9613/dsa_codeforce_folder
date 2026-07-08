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

struct node{
int dp,idx;
node(int d=0,int i=0) :dp(d),idx(i) {}
};

node better(node a,node b){
    return (a.dp>b.dp)?a:b;
}

struct segtree{
int n;
vector<node>st;
segtree(int n):n(n)
{
    st.assign(4*n+5,node());
}

void update(int p,node val,int id,int l,int r){
    if(l==r){
        st[id]=better(st[id],val);
        return ;
    }
    int mid=(l+r)/2;
    if(p<=mid){
        update(p,val,2*id,l,mid);
    }
    else
    {
        update(p,val,2*id+1,mid+1,r);
    }

    st[id]=better(st[2*id],st[2*id+1]);

}


void update(int p,node val){
    update(p,val,1,1,n);
}

node query(int ql,int qr,int id,int l,int r){
    if(ql>r || qr<l){
        return node();
    }
    if(ql<=l && r<=qr){
        return st[id];
    }
    int mid=(l+r)/2;
    return better(
        query(ql,qr,2*id,l,mid),query(ql,qr,2*id+1,mid+1,r)
    );

}

node query(int ql,int qr){
    if(ql>qr){
        return node();
    }

    return query(ql,qr,1,1,n);
}
};





void solve() {
    int n;
    ll d;cin>>n>>d;

    vll h(n+1);
    vll vals;
    for(int i=1;i<=n;i++){
        cin>>h[i];
        vals.push_back(h[i]);
    }

    sort(all(vals));
    vals.erase(unique(all(vals)),vals.end());
    int m=vals.size();
    segtree seg(m);
    vi dp(n+1,1);
    vi par(n+1,0);

    int bestLen=0;
    int bestIdx=0;

    for(int i=1;i<=n;i++){
        node best;
        int p1=upper_bound(all(vals),h[i]-d)-vals.begin();
        if(p1>0){
            best=better(best,seg.query(1,p1));
        }

        int p2=lower_bound(all(vals),h[i]+d)-vals.begin()+1;
        if(p2<=m){
            best=better(best,seg.query(p2,m));
        }
        dp[i]=best.dp+1;
        par[i]=best.idx;

        int pos=lower_bound(all(vals),h[i])-vals.begin()+1;
        seg.update(pos,node(dp[i],i));

        if(dp[i]>bestLen){
            bestLen=dp[i];
            bestIdx=i;
        }
    }

    vi ans;
    while(bestIdx){
        ans.push_back(bestIdx);
        bestIdx=par[bestIdx];
    }
    reverse(all(ans));

    cout<<ans.size()<<endl;
    for(int x:ans){
        cout<<x<<" ";
    }
    cout<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}