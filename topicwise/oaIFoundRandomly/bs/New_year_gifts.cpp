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

/*

let say sort all boxes with beauty in acending order;
.. to satisfy box for aj beauty finad all friends who want this box and among those i will select who demand largest extra cost;



*/

void solve() {
    int n,m;
    cin>>n>>m;
    ll k;
    cin>>k;
    vi a(m);
    for(int i=0;i<m;i++){
        cin>>a[i];
    }

    sort(all(a));
    vector<pair<int,ll>>f(n);
    ll sum_y=0;
    for(int i=0;i<n;i++){
        ll y,z;
        int x;
        cin>>x>>y>>z;
        sum_y+=y;
        f[i]={x,z-y};
    }
   k-=sum_y;
   sort(all(f));
   priority_queue<ll>pq;
   int p=0;
   int ans=0;
   for(int i=0;i<m;i++){
    while(p<n && f[p].first<=a[i]){
        pq.push(f[p].second);
        p++;
    }
    if(!pq.empty()){
        pq.pop();
        ans++;
    }
   }

   vll remaining;
   while(!pq.empty()){
    remaining.push_back(pq.top());
    pq.pop();
   }

   while(p<n){
    remaining.push_back(f[p].second);
    p++;
   }

   sort(all(remaining));
   for(ll cost:remaining){

    if(k>=cost){
        k-=cost;
        ans++;
    }
    else{
        break;
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
    cin >> t;
    while (t--) solve();
    return 0;
}