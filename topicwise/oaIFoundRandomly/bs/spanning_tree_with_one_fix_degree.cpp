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

struct DSU {
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n + 1);
        size.assign(n + 1, 1);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int v) {
        if (v == parent[v]) return v;
        return parent[v] = find(parent[v]);
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            if (size[a] < size[b]) swap(a, b);
            parent[b] = a;
            size[a] += size[b];
            return true;
        }
        return false;
    }
};

void solve() {

    int n,m,d;
    cin>>n>>m>>d;
    vector<pair<int,int>>edges;

    vi adj1;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        if(u==1){
            adj1.push_back(v);
        }
        else if(v==1){
            adj1.push_back(u);
        }
        else{
            edges.push_back({u,v});
        }
    }

    DSU dsu_comp(n);
    for(auto &e:edges)
    {
        dsu_comp.unite(e.first,e.second);
    }
    map<int,vi>comp_neig;
    for(int v:adj1){
        comp_neig[dsu_comp.find(v)].push_back(v);
    }
    int k=comp_neig.size();
    if(d<k || d>(int)adj1.size()){
        cout<<"NO"<<endl;
        return ;
    }
    cout<<"YES"<<endl;
    DSU final_dsu(n);
    vector<pair<int,int>>tree_edges;
    vi remain;
    for(auto &pair:comp_neig){
        int t=pair.second[0];
        // must;
        final_dsu.unite(1,t);
        tree_edges.push_back({1,t});
        for(int i=1;i<pair.second.size();i++){

            remain.push_back(pair.second[i]);
        }
    }


    int cdeg=k;
    for(int v:remain){
        if(cdeg==d){
            break;
        }
        if(final_dsu.unite(1,v)){
            tree_edges.push_back({1,v});
            cdeg++;
        }
    }

    for(auto &e:edges){

        if(final_dsu.unite(e.first,e.second)){
            tree_edges.push_back({e.first,e.second});
        }
    }

    for(auto &e:tree_edges){
        cout<<e.first<<" "<<e.second<<endl;
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