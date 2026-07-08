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
const int MAXN = 1e5 + 5;

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

int freq[MAXN];
int a[MAXN];
int cnt=0;
int ans[MAXN];
int BLOCK_SIZE;

int n;

struct query{
int l,r,id;
bool operator<(const query&other){
    int me=l/BLOCK_SIZE;
    int you=other.l/BLOCK_SIZE;
    if(me!=you){
     return  me<you;
    }
    if(me&1){
       return r<other.r;
    }
    return r>other.r;
}
};
void inline add(int x){
    // when iam adding x if freq[x] become x its contribute;
    if(x>n) return;
   if(freq[x]==x){
    cnt--;
   }
    freq[x]++;
    if(freq[x]==x){
        cnt++;
    }

    
}

void inline remove(int x){
    if(x>n) return;
   if(freq[x]==x){
    cnt--;
   }
   freq[x]--;
   if(freq[x]==x){
    cnt++;
   }
}


void solve() {
int q;
cin>>n>>q;
for(int i=1;i<=n;i++){
    cin>>a[i];
}
BLOCK_SIZE=sqrt(n)+1;

vector<query>queries(q);
for(int i=0;i<q;i++)
{
    int l,r;
    cin>>l>>r;
    queries[i]={l,r,i};
}

sort(all(queries));
int L=1,R=0;
for(auto &qr:queries){
    while(R<qr.r){
        R++;
        add(a[R]);

    }
    while(R>qr.r){
        remove(a[R]);
        R--;
    }

    while(L<qr.l){
        remove(a[L]);
        L++;
    }
    while(L>qr.l){
        L--;
        add(a[L]);
    }
    ans[qr.id]=cnt;
}

for(int i=0;i<q;i++){
    cout<<ans[i]<<endl;
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