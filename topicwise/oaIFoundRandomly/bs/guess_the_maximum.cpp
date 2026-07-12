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

int query(int l,int r){
    if(l>=r){
        return -1;
    }
    cout<<"? "<<l<<" "<<r<<endl;
    int ans;
    cin>>ans;
    return ans;
}

void solve() {
    int n;
    cin>>n;
    int p=query(1,n);
    if(p>1 && query(1,p)==p){
        int low=1,high=p-1;
        int ans=1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(query(mid,p)==p){
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        cout << "! " << ans << endl;
    }
    else{
        //max in [p+1,n];
      int  low=p+1,high=n;
      int ans=n;
      while(low<=high){
        int mid=low+(high-low)/2;
        if(query(p,mid)==p){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
      }
      cout<<"! "<<ans<<endl;
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