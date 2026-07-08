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
// its a infinite long chess board;



void solve() {

    ll b,w;
    cin>>b>>w;
    if(w>3*b+1 ||b>3*w+1){
        cout<<"NO"<<endl;
        return ;
    }
    cout<<"YES"<<endl;
    vector<pair<int,int>>ans;
    if(w>=b){
        for(int i=0;i<2*b;i++){
            ans.push_back({2,2+i});
        }
        int remain=w-b;
        if(remain>0){
            ans.push_back({2,1});
            remain--;
        }
        if(remain>0){
            ans.push_back({2,2+2*b});
            remain--;
        }
        for(int i=0;i<b && remain>0;i++){
            int black=3+2*i;
            ans.push_back({1,black});
            remain--;

            if(remain>0){
                ans.push_back({3,black});
                remain--;
            }
        }
    }else{
        for(int i=0;i<2*w;i++){
            ans.push_back({3,3+i});
        }
        int remain = b - w;
        if(remain>0){
            ans.push_back({3,2});
            remain--;
        }

        if(remain>0){
            ans.push_back({3,3+2*w});
            remain--;
        }

        for(int i=0;i<w && remain>0 ;i++){
            int white=3+2*i;
            ans.push_back({2,white});
            remain--;

            if(remain>0){
                ans.push_back({4,white});
                remain--;
            }
        }
    }

    for(auto &[x,y]:ans){
        cout<<x<<" "<<y<<endl;
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