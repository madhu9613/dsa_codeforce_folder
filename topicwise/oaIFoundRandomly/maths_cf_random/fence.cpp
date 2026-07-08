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

ll dp[205][40005][2];
// 0->red;
//1 ->green;


void solve() {
    int n;
    int a,b;
    cin>>n>>a>>b;
    vll h(n+1);
    ll total=0;
    for(int i=1;i<=n;i++){
        cin>>h[i];
        total+=h[i];
    }

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=a;j++){
            for(int s=0;s<2;s++){
                dp[i][j][s]=INF;
            }
        }
    }
    dp[0][0][0]=0;
    dp[0][0][1]=0;
    ll csum=0;
    for(int i=1;i<=n;i++){
        csum+=h[i];
        for(int j=0;j<=a;j++){
            int g_used=csum-j;
            if(g_used>=0 && g_used<=b){
                
                if(j>=h[i])
                {
                // painting using red;
                // if i paint h[i] red then prev red total used was j-h[i]
                dp[i][j][0]=min(dp[i][j][0],dp[i-1][j-h[i]][0]);
                // okay ,now i am painting red but prev was green l
                dp[i][j][0]=min(dp[i][j][0],dp[i-1][j-h[i]][1]+min(h[i-1],h[i]));
               
                }

                // now i am painting 

                if(g_used>=h[i]){

                dp[i][j][1]=min(dp[i][j][1],dp[i-1][j][1]);
                dp[i][j][1]=min(dp[i][j][1],dp[i-1][j][0]+min(h[i-1],h[i]));

                }
            }
        }
    }

    ll ans=INF;
    for(int j=0;j<=a;j++){
        ans=min({ans,dp[n][j][0],dp[n][j][1]});
    }
    if(ans==INF){
        cout<<-1<<endl;
    }else{
        cout<<ans<<endl;
    }

    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
   // precompute();
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t = 1;
    while (t--) solve();
    return 0;
}