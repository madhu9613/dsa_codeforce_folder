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
int n,m;
int BLOCK_SIZE;
int a[MAXN];
int nxt[MAXN];
int jumps[MAXN];
void update(int id){
    int block_id=id/BLOCK_SIZE;
    int l=block_id*BLOCK_SIZE;
    int r=min(n-1,l+BLOCK_SIZE-1);
    for(int i=r;i>=l;i--){
        int to=i+a[i];
        if(to>r || to>=n){
            nxt[i]=to;
            jumps[i]=1;
        }
        else{
            nxt[i]=nxt[to];
            jumps[i]=jumps[to]+1;
        }

    }
}


void solve() {
    cin>>n>>m;
    BLOCK_SIZE=sqrt(n)+1;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    for(int i=n-1;i>=0;i-=BLOCK_SIZE){
        update(i);
    }
    while(m--){
        int t;
        cin>>t;
        if(t==0)
        {
            int x,y;
            cin>>x>>y;
            x--;
            a[x]=y;
            update(x);
        }
        else{
            int x;
            cin>>x;
            x--;
            int total=0;
            int last=x;
            while(x<n){
                last=x;
                if(nxt[x]>=n){

                    while(x+a[x]<n){
                        total++;
                        x=x+a[x];
                    }
                    total++;
                    last=x;
                    break;
                }
                total+=jumps[x];
                x=nxt[x];
            }

            cout<<last+1<<" "<<total<<endl;
        }
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