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


struct student{
ll skill;
int id;
};
void solve() {
    int n;
    cin>>n;
    vector<student>a(n+1);
    for(int i=1;i<=n;i++)
{
    cin>>a[i].skill;
    a[i].id=i;
}
sort(a.begin()+1,a.end());
vll dp(n+1,INF);
vi par(n+1,-1);
dp[0]=0;
for(int i=3;i<=n;i++){
    for(int sz=3;sz<=5;sz++){
        if(i-sz>=0){
            ll cost=dp[i-sz]+a[i].skill-a[i-sz+1].skill;
            if(cost<dp[i]){
                dp[i]=cost;
                par[i]=i-sz;
            }
        }
    }
}

vi teams(n+1);
int cur=n;
int tcnt=0;
while(cur>0){
    tcnt++;
    int prev=par[cur];
    for(int i=prev+1;i<=cur;i++){
        teams[a[i].id]=tcnt;
    }
    cur=prev;
}

cout<<dp[n]<<" "<<tcnt<<endl;
for(int i=1;i<=n;i++){
    cout<<teams[i]<<" ";
}
cout<<endl;

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