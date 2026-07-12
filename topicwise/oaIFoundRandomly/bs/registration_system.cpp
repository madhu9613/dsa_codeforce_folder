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


void solve() {
    int n;
    cin>>n;
    unordered_map<string,int>cnt;
    for(int i=0;i<n;i++){
    string s;
    cin>>s;
    if(cnt[s]==0){
        // first time;
        cnt[s]=1;
        cout<<"OK"<<endl;
    }
    else{
        int x=cnt[s];
        while(cnt.count(s+to_string(x))){
            x++;
        }
        string t=s+to_string(x);
        cout<<t<<endl;
        cnt[s]=x+1;
        cnt[t]=1;
    }
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