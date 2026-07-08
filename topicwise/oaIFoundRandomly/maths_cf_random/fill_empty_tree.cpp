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

vector<vector<int>>adj;
vi tin;
vi tout;
int timer=0;
int n,q;

void dfs(int u,int p=-1){
    tin[u]=++timer;
    for(int v:adj[u]){
        if(v==p){
           continue;
        }
        dfs(v,u);
    }
    tout[u]=timer;
}

struct fill_seg{

    vector<int>st,lazy;
    int n;

    fill_seg(int n){
        this->n=n;
        st.assign(4*n,0);
        lazy.assign(4*n,-1);
    }

    void push(int node,int l,int r){
        if (lazy[node] == -1)
        {
            return ;
        }
        st[node]=lazy[node];
        if(l!=r){
            lazy[2 * node] = lazy[node];
            lazy[2 * node + 1] = lazy[node];
        }

        lazy[node] = -1;
    }

    // range update;
    void update(int node,int l,int r,int ql,int qr,int val){
        push(node,l,r);
        if(r<ql || l>qr){
            return ;
        }
        if(ql<=l && qr>=r){
            lazy[node]=val;
            push(node,l,r);
            return ;
        }
        int m=(l+r)/2;
        update(2*node,l,m,ql,qr,val);
        update(2*node+1,m+1,r,ql,qr,val);
    }

    // point query;
    int query(int node,int l,int r,int idx){
        push(node,l,r);
        if(l==r){
            return st[node];
        }
        int m=(l+r)/2;
        if(idx<=m){
         return   query(2*node,l,m,idx);
        }
            return query(2*node+1,m+1,r,idx);
        


    }

    void update(int l,int r,int val){
        update(1,1,n,l,r,val);
    }
    int query(int idx){
        return query(1,1,n,idx);
    }
};

struct empty_seg{
int n;
vi st;
empty_seg(int n){
    this->n=n;
    st.assign(4*n,0);
}

void update(int node,int l,int r,int idx,int val){
    if(l==r){
        st[node]=val;
        return ;
    }
    int m=(l+r)/2;
    if(idx<=m){
        update(2*node,l,m,idx,val);
    }else{
        update(2*node+1,m+1,r,idx,val);
    }

    st[node]=max(st[2*node],st[2*node+1]);
}

int query(int node,int l,int r,int ql,int qr){
    if(r<ql || l>qr){
        return 0;
    }
    if(ql<=l && r<=qr){
        return st[node];
    }
    int m=(l+r)/2;
    return max(query(2*node,l,m,ql,qr),query(2*node+1,m+1,r,ql,qr));

}

void update(int idx,int val){
    update(1,1,n,idx,val);
}
int query(int l,int r){
    return query(1,1,n,l,r);
}
};


void solve() {
    cin>>n;
    adj.resize(n+1);
    tin.resize(n+1);
    tout.resize(n+1);
    for(int i=1;i<n;i++){
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    fill_seg seg1(n);
    empty_seg seg2(n);

    cin>>q;
    for(int t=1;t<=q;t++){
        int type,v;
        cin>>type>>v;
        if(type==1){
            // fill subtree ->range update
            seg1.update(tin[v],tout[v],t);
        }
        else if(type==2){
            seg2.update(tin[v],t); // mark empty point for this ;
        }
        else{
            int last_fill=seg1.query(tin[v]);
            int last_empty=seg2.query(tin[v],tout[v]); // recent time when this vetex is affected;;

            cout<<(last_fill>last_empty)<<endl;
        }
    }


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}