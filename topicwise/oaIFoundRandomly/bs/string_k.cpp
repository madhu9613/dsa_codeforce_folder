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

int dp[1005][1005][12][2];


void solve() {
int n,m,k;
cin>>n>>m>>k;
string s,t;
cin>>s>>t;
s=" "+s;
t=" "+t;
for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
        for(int x=1;x<=k;x++){
            int op1=max(dp[i-1][j][x][0],dp[i-1][j][x][1]);
            int op2=max(dp[i][j-1][x][0],dp[i][j-1][x][1]);
            dp[i][j][x][0]=max(op1,op2); // not extending ;


            if(s[i]==t[j]){
                int cont=dp[i-1][j-1][x][1]; // continue with prev;
                int snew=max(dp[i-1][j-1][x-1][0],dp[i-1][j-1][x-1][1]);

                dp[i][j][x][1]=max(cont,snew)+1; //inc in length

            }
          
        }
    }
}    

cout<<max(dp[n][m][k][0],dp[n][m][k][1])<<endl;
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