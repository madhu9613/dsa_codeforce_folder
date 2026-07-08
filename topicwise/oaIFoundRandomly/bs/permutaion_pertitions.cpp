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

void solve() {

    int n,k;
    cin>>n>>k;
    vi a(n);
    vi pos(n+1);
  
    set<int>s; // position of top k element;
    for(int i=0;i<n;i++){
        cin>>a[i];
        pos[a[i]]=i+1;
    }
    ll sum=0;
    sort(rall(a));
    
    for(int i=0;i<k;i++){
        
        s.insert(pos[a[i]]);
        sum+=a[i];
    }
    ll cnt = 1;

    for (auto it = next(s.begin()); it != s.end(); it++)
    {
        auto prev_it = prev(it);
        cnt = (cnt * (*it - *prev_it)) % MOD;
    }

    cout << sum <<" "<<cnt<<endl;
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