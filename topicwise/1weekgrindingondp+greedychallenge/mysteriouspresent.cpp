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

struct env{
int w,h,idx;
};
void solve() {
    int n,W,H;
    cin>>n>>W>>H;
    vector<env>a;
    for(int i=1;i<=n;i++){
        int w,h;cin>>w>>h;
        if(w>W &&  h>H){
            a.push_back({w,h,i});
        }
    }
    if(a.empty()){
        cout<<0<<endl;
        return;
    }
    sort(all(a),[](env x,env y){
if(x.w==y.w) return x.h>y.h;
return x.w<y.w; 
    });

    int m=a.size();
    vi dp(m,1),par(m,-1);
    int best=0,last=-1;
    for(int i=0;i<m;i++){
        for(int j=0;j<i;j++){
            if(a[j].h<a[i].h && a[j].w<a[i].w){
                if(dp[j]+1>dp[i]){
                    dp[i]=dp[j]+1;
                    par[i]=j;
                }
            }
        }
        if(dp[i]>best){
            best=dp[i];
            last=i;
        }

    }

    vi ans;
    while(last!=-1){
        ans.push_back(a[last].idx);
        last=par[last];
    }
    reverse(all(ans));
    cout<<best<<endl;
    for(int x:ans){
        cout<<x<<" ";
    }
    cout<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    
    while (t--) solve();

    return 0;
}