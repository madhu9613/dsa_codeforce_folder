// Author: Madhujya Rajkhowa
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define all(x) (x).begin(), (x).end()
#define endl '\n'

const int MOD = 1e9 + 7;
const int INF = INT_MAX;
//finally understand it;
const int MAXN = 1e6 + 5;
ll fact[MAXN], invfact[MAXN];

ll modpow(ll a, ll b, ll mod = MOD) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}


void solve() {
 ll n,k;cin>>n>>k;
 cout<<modpow(n,k)<<endl;   
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin>>t;
    while (t--) solve();
    return 0;
}