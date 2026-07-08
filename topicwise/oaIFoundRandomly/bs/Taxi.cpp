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
    vi s(n);
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    // 1 1 1 1 2 3 3
   // (1,3),(1,3) (1,1,2)
   // (1,1,1,1),(2),(3),(3)

   sort(all(s));
   int cnt=0;
   int i=0;
   int j=n-1;
   while (i<=j)
   {
    if(s[j]==4){
        cnt++;
        j--;
    }
    else if(s[j]<4){
        int pick=s[j];

        while(pick+s[i]<=4){
            i++;
            pick+=s[i];
        }
        j--;
        cnt++;
    }

   }

   cout<<cnt<<endl;
   
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