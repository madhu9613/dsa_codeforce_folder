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
const int MOD = 998244353;
const int MAXN = 3e5 + 5;

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

vi adj[MAXN];
int color[MAXN];
ll cnt[2];
ll pow2[MAXN];
void precom(){
    pow2[0]=1;
    for(int i=1;i<MAXN;i++){
        pow2[i]=(pow2[i-1]*2)%MOD;
    }
}

bool dfs(int u,int c){
color[u]=c;
cnt[c]++;
for(int v:adj[u]){
    if(color[v]==-1){
        if(!dfs(v,1-c)){
            return false;
        }
    }
    else{
       if(color[v]==c){
        return false;
       }
    }
   
}
return true;
}
void solve() {
int n,m;cin>>n>>m;
for(int i=1;i<=n;i++){
    adj[i].clear();
}

for(int i=0;i<m;i++){
    int u,v;
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
}
for (int i = 1; i <= n; i++)
    color[i] = -1;
ll ans=1;
for(int i=1;i<=n;i++){
    if(color[i]==-1){

        cnt[0] = cnt[1] = 0;
        if(!dfs(i,0)){

        cout<<0<<endl;
          return;
        }else{

            ll op1=pow2[cnt[0]];
            ll op2=pow2[cnt[1]];

            ll ways=(op1+op2)%MOD;
            ans=(ans*ways)%MOD;
        }
    }
}

cout<<ans<<endl;

/***
 * odd:1,3
 * even:2;
 * 
 * op1: color0 become odd;
 * op2:color1 become odd;
 * so 2^cnt0 +2^cnt1; for each component;
 * 
 * 
 * 
 */




    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
   // precompute();
   // freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);
   precom();
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}