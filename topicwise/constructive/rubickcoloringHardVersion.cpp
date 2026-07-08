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

void solve() {
    ll k; 
    int n;cin>>k>>n;
    map<string, int> mp = {
        {"white", 0}, {"yellow", 1}, {"green", 2}, {"blue", 3}, {"red", 4}, {"orange", 5}
    };
    map<ll,int>pcolor;
    set<ll>a;
    for(int i=0;i<n;i++){
        ll u;string s;
        cin>>u>>s;
        pcolor[u]=mp[s];
        ll cur=u;
        while(cur>=1){
            if(a.count(cur)){
                break;
            }
            a.insert(cur);
            cur/=2;
        }
    }
    vll nodes(rall(a));
    map<ll,vll>dp;

    for(ll u:nodes){
        dp[u]=vll(6,0);
        vi allowed;
        if(pcolor.count(u)){
            allowed.push_back(pcolor[u]);
        }
        else{
            for(int c=0;c<6;c++){
                allowed.push_back(c);
            }
        }
        for(int c:allowed){
            ll ways=1;
            ll left=2*u;
            if(a.count(left)){
                ll childways=0;
                for(int cchild=0;cchild<6;++cchild){
                    if(cchild!=c && cchild!=(c^1))
                    {
                        childways=(childways+dp[left][cchild])%MOD;

                    }
                }
                ways=(ways*childways)%MOD;
            }

            ll right=2*u+1;
            if(a.count(right)){
                ll childways=0;
                for(int cchild=0;cchild<6;++cchild){

                    if(cchild!=c && cchild!=(c^1)){
                        childways=(childways+dp[right][cchild])%MOD;
                    }
                }
                ways=(ways*childways)%MOD;
            }
            dp[u][c]=ways;
        }

    }

    ll ans1=0;
    for(int c=0;c<6;c++){
        ans1=(ans1+dp[1][c])%MOD;
    }
    ll totalnodes=(1LL<<k)-1;
    ll unmarked=totalnodes-a.size();
    ll res=(ans1*modpow(4,unmarked))%MOD;

    cout<<res<<endl;


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}