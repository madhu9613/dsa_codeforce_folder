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

void solve() {
    int n;cin>>n;
    vi a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int g=a[0];
    for(auto x:a){
        g=gcd(g,x);
    }
    int cnt=count(all(a),g);
    if(cnt){
        cout<<n-cnt<<endl;
        return;
    }

    vi dist(5005,INT_MAX);
    queue<int>q;
    for(int x:a){
        dist[x]=1;
        q.push(x);
    }
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(int y:a){
            int z=gcd(x,y);
            if(dist[z]>dist[x]+1){
                dist[z]=dist[x]+1;
                q.push(z);
            }
        }
    }

    int k=dist[g];
    cout<<n+k-2<<endl;

    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}