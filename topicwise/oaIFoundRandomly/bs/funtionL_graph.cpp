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
const int MAXN = 1e5 + 5;

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
const int LOG=35;
int nxt[MAXN][LOG];
ll sum_w[MAXN][LOG];
ll min_w[MAXN][LOG];

void solve() {

    int n;
    ll k;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>nxt[i][0];
    }
    for(int i=0;i<n;i++){
        cin>>sum_w[i][0];
        min_w[i][0]=sum_w[i][0];
    }

    for(int j=1;j<LOG;j++){
        for(int i=0;i<n;i++){
            nxt[i][j]=nxt[nxt[i][j-1]][j-1];
            sum_w[i][j]=sum_w[i][j-1]+sum_w[nxt[i][j-1]][j-1];
            min_w[i][j]=min(min_w[i][j-1],min_w[nxt[i][j-1]][j-1]);
        }
    }
    for(int i=0;i<n;i++){
        int cur=i;
        ll sum=0;
        ll mini=INF;
        for(int j=0;j<LOG;j++){
            if((k>>j)&1){
            sum+=sum_w[cur][j];
            mini=min(mini,min_w[cur][j]);
            cur=nxt[cur][j];
            }
        }

        cout<<sum<<" "<<mini<<endl;
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