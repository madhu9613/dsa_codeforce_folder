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

const ll M1 = 1000000007;
const ll M2 = 998244353;
const ll B1 = 313;
const ll B2 = 317;

const int MAXN = 1000005;
ll p1_pow[MAXN], p2_pow[MAXN];

void precomp(){
    p1_pow[0]=1;
    p2_pow[0]=1;
    for(int i=1;i<MAXN;i++){
        p1_pow[i]=(p1_pow[i-1]*B1)%M1;
        p2_pow[i]=(p2_pow[i-1]*B2)%M2;
    }
}

struct node{
int len;
ll f1,b1,f2,b2;
node(){
    len=0;
    f1=b1=f2=b2=0;
}
node(char c){
    len=1;
    ll val=c-'a'+1;
    f1=b1=f2=b2=val;
}

};

node merge(const node&L,const node &R){
    if(L.len==0){
        return R;
    }
    if(R.len==0){
        return L;
    }
    node res;
    res.len=L.len+R.len;
    res.f1=(L.f1*p1_pow[R.len]+R.f1)%M1;
    res.f2=(L.f2*p2_pow[R.len]+R.f2)%M2;

    res.b1=(R.b1*p1_pow[L.len]+L.b1)%M1;
    res.b2=(R.b2*p2_pow[L.len]+L.b2)%M2;
return res;
}

node tree[2*MAXN];
int n;
void build(const string &s){
    for(int i=0;i<n;i++){
        tree[n+i]=node(s[i]);
    }
    for(int i=n-1;i>0;i--){
        tree[i]=merge(tree[i<<1],tree[i<<1|1]);
    }
}
void update(int p,char c){
    p+=n;
    tree[p]=node(c);
    for(p>>=1;p>0;p>>=1){
        tree[p]=merge(tree[p<<1],tree[p<<1|1]);
    }
}
node query(int l,int r){
    node resL,resR;
    for(l+=n,r+=n+1;l<r;l>>=1,r>>=1){
        if(l&1){
            resL=merge(resL,tree[l++]);
        }
        if(r&1){
            resR=merge(tree[--r],resR);
        }
    }

    return merge(resL,resR);
}
void solve() {
    
    int q;
    cin>>n>>q;
    string s;
    cin>>s;
    build(s);
    while(q--){
        int type;
        cin>>type;
        if(type==1){
            int x;
            char c;
            cin>>x>>c;
            update(x-1,c);
        }
        else{
            int L,R;
            cin>>L>>R;
            node res=query(L-1,R-1);
            if(res.f1==res.b1 && res.f2==res.b2){
                cout<<"Yes"<<endl;
            }else{
                cout<<"No"<<endl;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
   // precompute();
   precomp();
    int t = 1;
    while (t--) solve();
    return 0;
}