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

struct DSU
{
    vector<int> p;

    DSU(int n = 0)
    {
        p.resize(n + 1);
        for (int i = 1; i <= n; i++)
            p[i] = i;
    }

    int find(int x)
    {
        if (p[x] == x)
            return x;
        return p[x] = find(p[x]);
    }

    void unite(int a, int b)
    {
        a = find(a);
        b = find(b);
        if (a != b)
            p[a] = b;
    }
};
void solve() {
    int n,m;
    cin >> n >> m;
    vector<pair<int, int>> edges(m + 2);

    
    for(int i=1;i<=m;i++){
        int x,y;cin>>x>>y;
        edges[i]={x,y};
    }
    vector<DSU>ldsu(m+1,DSU(n));
    for(int i=1;i<=m;i++){
        ldsu[i]=ldsu[i-1];
        ldsu[i].unite(edges[i].first,edges[i].second);
    }

    vector<DSU> rdsu(m + 2, DSU(n));
    for (int i = m; i >= 1; i--)
    {
        rdsu[i] = rdsu[i + 1];
        rdsu[i].unite(edges[i].first, edges[i].second);
    }
    int k;cin>>k;
    while(k--){
        int l,r;
        cin>>l>>r;
        DSU dsu=ldsu[l-1];
        for(int i=1;i<=n;i++){
            dsu.unite(i,rdsu[r+1].find(i));
        }
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(dsu.find(i)==i){
                cnt++;
            }
        }
        cout<<cnt<<endl;
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