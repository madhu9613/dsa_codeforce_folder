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
    string s;
    cin>>s;
    int x;
    cin>>x;
    int n=s.size();
    string res(n,'1');
    for(int i=0;i<n;i++){
        if(s[i]=='0'){
            if(i-x>=0){
                res[i-x]='0';
            }
            if(i+x<n){
                res[i+x]='0';
            }
        }
    }
    bool pos=true;
    for(int i=0;i<n;i++){
        if(s[i]=='1'){
           
            bool found=false;
            if(i-x>=0 && res[i-x]=='1'){
               found=true;
            }
            if(i+x<n && res[i+x]=='1'){
                found=true;
            }
            if(!found){
                pos=false;
                break;
            }
        }
    }
    if(pos){
        cout<<res<<endl;
    }
    else{
        cout<<-1<<endl;
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
   // precompute();
   // freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}