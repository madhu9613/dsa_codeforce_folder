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

unordered_set<ll>cubes;
void precomp(){
    for(ll i=1;i<=10000;i++)
    {
        cubes.insert(i*i*i);
    }
}
void solve() {
// x=> is any a,b exist st; a^3+b^3=x;
// let say a cubic number is y; then x-y must be also cubic 

ll x;
cin>>x;
for(ll i=1;i*i*i<x;i++){
    int a=i*i*i;
    int b=x-a;
    if(cubes.count(b)){
        cout<<"YES"<<endl;
        return ;
    }
}

cout<<"NO"<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
   // precompute();
   // freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);

   precomp();
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}