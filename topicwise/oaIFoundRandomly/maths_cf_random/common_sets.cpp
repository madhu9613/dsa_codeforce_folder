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
vector<vector<int>>sets(n);
map<int,int>freq;
for(int i=0;i<n;i++){
    int k;
    cin>>k;
    sets[i].resize(k);
    for(int j=0;j<k;j++){
        cin>>sets[i][j];
        freq[sets[i][j]]++;
    }
}   

map<int,int>last;
vector<map<int,int>>shared(n);
for(int i=0;i<n;i++){
    for(int x:sets[i]){
        if(freq[x]>1){
            if(last.count(x)){
                int prev=last[x];
                shared[i][prev]++;

                if(shared[i][prev]>=2){
                    cout<<prev+1<<" "<<i+1<<endl;
                    return ;
                }
            }

            last[x]=i;
        }
    }
}


cout<<-1<<endl;


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