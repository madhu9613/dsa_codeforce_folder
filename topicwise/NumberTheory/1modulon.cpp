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

// need to chose a subsequence such that product of all element is ==1 mod n; i mean can represet in 1+kn;

void solve() {
    int n;cin>>n;
    vi res;
    ll prod=1;
    for(int i=1;i<n;i++){
        if(gcd(i,n)==1){
            res.push_back(i);
            prod=(prod*i)%n;
        }
    }
    if(prod==1){
        cout<<res.size()<<endl;
        for(int x:res){
            cout<<x<<" ";
        }
        cout<<endl;
    }else{
        cout<<res.size()-1<<endl;
        for(int x:res){
            if(x!=prod){
                cout<<x<<" ";
            }
        }
        cout<<endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}