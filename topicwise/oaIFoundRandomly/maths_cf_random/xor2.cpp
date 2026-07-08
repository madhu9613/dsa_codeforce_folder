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

const ll INF = 1e9;
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

const int MAX_VAL=5000;
const int MAX_XOR=1<<13;

void solve() {
 
    int n;
    cin>>n;
    vector<vi>pos(MAX_VAL+1);
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        
            pos[a].push_back(i);
    }

    vi dp(MAX_XOR,INF);
    dp[0]=-1;
    vi rechable;
    rechable.push_back(0);
    vector<bool>in_reach(MAX_XOR,false);
    in_reach[0]=true;
    for(int v=1;v<=MAX_VAL;v++){
        if(pos[v].empty()) continue;
        vi ndp=dp;
        vi new_reach;
        for(int x:rechable){
            int idx=dp[x]; // min idx of last val;
            auto it=upper_bound(all(pos[v]),idx);
            if(it!=pos[v].end()){
                int nx=x^v;
                if(*it<ndp[nx]){
                    ndp[nx]=*it;
                    if(!in_reach[nx]){
                        in_reach[nx]=true;
                        new_reach.push_back(nx);
                    }
                }
            }

        }
        dp=ndp;
        for(int nx:new_reach)
        {
            rechable.push_back(nx);
                }
    }

    vi ans;
    for(int x=0;x<MAX_XOR;x++){
        if(dp[x]!=INF){
            ans.push_back(x);
        }
    }
    cout<<ans.size()<<endl;
    for(int x:ans){

        cout<<x<<" ";
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