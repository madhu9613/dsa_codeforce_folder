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
int n, m;
vector<string>grid;

bool dfs(int r,int c){
    if(r>=n || c>=m || grid[r][c]=='#')
    {
        return false;
    }
    if(r==n-1 && c==m-1){
        return true;
    }
    if(r!=0 || c!=0){
        grid[r][c]='#';
    }
    if(dfs(r+1,c)){
        return true;
    }

    if(dfs(r,c+1)){
        return true;
    }
    return false;
}

void solve()
{
    cin>>n>>m;
    grid.resize(n);
    for(int i=0;i<n;i++){
        cin>>grid[i];
    }

    if(!dfs(0,0))
    {
        cout<<0<<endl;
        return ;
    }
    if(!dfs(0,0)){
        cout<<1<<endl;
        return;
    }

    cout<<2<<endl;


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