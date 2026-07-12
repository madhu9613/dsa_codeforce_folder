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
    int n,k;
    cin>>n>>k;
    map<int,int>freq;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        freq[x]++;
    }
    vi valid;
    for(auto const &[num,count]:freq){
        if(count>=k){
            valid.push_back(num);
        }
    }
    if(valid.empty()){
        cout<<-1<<endl;
        return;

    }
    int max_len=-1;
    int ansl=-1,ansr=-1;
    int curl=valid[0];
    int curr=valid[0];
    int m=valid.size();
    for(int i=1;i<m;i++){
        if(valid[i]==valid[i-1]+1){
            curr=valid[i];
        }
        else{
            if(curr-curl>max_len){
                max_len=curr-curl;
                ansl=curl;
                ansr=curr;
            }

            curl=valid[i];
            curr=valid[i];
        }
    }

    if(curr-curl>max_len){
        ansl=curl;
        ansr=curr;

    }
    cout<<ansl<<" "<<ansr<<endl;
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