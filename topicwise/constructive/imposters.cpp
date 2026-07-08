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

vector<vector<pair<int,int>>>adj;
vi color;

bool dfs(int u,int c,int &cnt0,int &cnt1){
    color[u]=c;
    if(c==0){
        cnt0++;
    }else{
        cnt1++;
    }

    for(auto &[v,type]:adj[u]){
        int exp=c^type;
        if(color[v]==-1){
            if(!dfs(v,exp,cnt0,cnt1)){
                return false;
            }
        }else{
            if(color[v]!=exp){
                return false;
            }
        }
    }
    return true;
}

void solve() {
    int n,m;cin>>n>>m;
    adj.assign(n+1,{});
    color.assign(n+1,-1);
    for(int i=0;i<m;i++){
        int u,v;
        string s;
        cin>>u>>v>>s;
        if (s == "crewmate"){
            adj[u].push_back({v,0});
            adj[v].push_back({u,0});
        }else{
            adj[u].push_back({v,1});
            adj[v].push_back({u,1});
        }
    }

    int ans=0;
    for(int i=1;i<=n;i++){
        if(color[i]==-1){
            int cnt0=0,cnt1=0;
            if(!dfs(i,0,cnt0,cnt1)){
                cout<<-1<<endl;
                return;
            }
            ans+=max(cnt0,cnt1);
        }
    }

    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}