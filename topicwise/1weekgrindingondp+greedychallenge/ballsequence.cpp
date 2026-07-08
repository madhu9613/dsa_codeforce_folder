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
void solve()
{
    int ti, td, tr, te;
    cin >> ti >> td >> tr >> te;

    string a, b;
    cin >> a >> b;

    int n = a.size(), m = b.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1));

    for (int i = 0; i <= n; i++)
      {  dp[i][0] = i * td;}

    for (int j = 0; j <= m; j++){
        dp[0][j] = j * ti;
    }

    vi lastA(26,0),lastB(26);

    for(int i=1;i<=n;i++){
        fill(all(lastB),0);
        for(int j=1;j<=m;j++){
            dp[i][j]=min({
                dp[i][j-1]+ti,
                dp[i-1][j]+td,
                dp[i-1][j-1]+(a[i-1]==b[j-1]?0:tr)

            });
            int k=lastA[b[j-1]-'a'];
            int l=lastB[a[i-1]-'a'];
            if(k>0 && l>0){
                dp[i][j]=min(dp[i][j],dp[k-1][l-1]+(i-k-1)*td+(j-l-1)*ti+te);
            }

            lastB[b[j-1]-'a']=j;
        }
        lastA[a[i-1]-'a']=i;
    }


    cout << dp[n][m] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) solve();

    return 0;
}