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
struct state{
int l,w,type;
};
void solve() {
int n,L;cin>>n>>L;
vector<state>states;
for(int i=0;i<n;i++){
    int x,y;cin>>x>>y;
    states.push_back({x,y,i});
    if(x!=y){
        states.push_back({y,x,i});
    }
}
int m=states.size();
vector<vi>dp(L+1,vi(m,0));
for(int i=0;i<m;i++){
    if(states[i].l<=L){
        dp[states[i].l][i]=1;
    }
}

for(int len=1;len<=L;len++){
    for(int i=0;i<m;i++){
        if(dp[len][i]==0){
            continue;
        }
        for(int j=0;j<m;j++){
            if(states[i].type==states[j].type){
                continue;
            }

            if(states[i].w!=states[j].l){
                continue;
            }

            int new_len=len+states[j].l;
            if(new_len>L){
                continue;

            }

            dp[new_len][j]=((dp[new_len][j]+dp[len][i]))%MOD;
        }
    }


}
int ans = 0;
for (int i = 0; i < m; i++)
{
    ans = (ans + dp[L][i]) % MOD;
}
cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}