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
int n,m;
cin>>n>>m;
vll a(n),b(m);

for(int i=0;i<n;i++){
    cin>>a[i];
}
for(int i=0;i<m;i++){
    cin>>b[i];
}
ll ans=0;
ll L=0,H=3e9;

auto can=[&](ll r)->bool{

    map<ll,int>diff;
    for(int x:b){
        diff[x];
        diff[x-r]++;
        diff[x+r+1]--;
    }

    int cover=0;
    auto it=diff.begin();
    for(ll x:a){
        // process all events before this person;
        while(it!=diff.end() && it->first<=x){
         
            cover+=it->second;
            it++;
        }

        if(cover==0){
            return false;
        }
    }

    return true;
};
while(L<=H){
    ll M=L+(H-L)/2;
    if(can(M)){
        ans=M;
        H=M-1;
    }
    else{
        L=M+1;
    }
}

cout<<ans<<endl;

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