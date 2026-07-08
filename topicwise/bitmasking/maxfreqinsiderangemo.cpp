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

// Fast exponentiation (a^b % mod)
ll modpow(ll a, ll b, ll mod = MOD) {
    ll res = 1;
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

// GCD
ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

// LCM
ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

const int MAXN=3e5+5;
int n,q;
int a[MAXN];
int freq[MAXN],cnt[MAXN];
int ans[MAXN];
int maxf=0;
struct query
{
    int l,r,idx;
};
int block;
bool cmp(query a,query b){
    if(a.l/block!=b.l/block){
        return a.l<b.l;
    }
    return a.r<b.r;
}

void add(int x){
    cnt[freq[x]]--;
    freq[x]++;
    cnt[freq[x]]++;
    maxf=max(maxf,freq[x]);
}

void remv(int x){
 cnt[freq[x]]--;
 if(freq[x]==maxf && cnt[freq[x]]==0){
    maxf--;
 }
 freq[x]--;
 cnt[freq[x]]++;
}

void solve() {

    cin>>n>>q;
    for(int i=1;i<=n;i++){

        cin>>a[i];
    }

    vector<query>quries(q);
    for(int i=0;i<q;i++){
        cin>>quries[i].l>>quries[i].r;
        quries[i].idx=i;
    }
    block=sqrt(n);
    sort(all(quries),cmp);
    int L=1,R=0;
    for (auto &qq : quries)
    {
        int l=qq.l,r=qq.r;
        while(R<r){
            add(a[++R]);
        }
        while(R>r){
            remv(a[R--]);
        }
        while(L<l){
            remv(a[L++]);
        }
        while(L>l){
            add(a[--L]);
        }
        int len=r-l+1;
        ans[qq.idx]=max(1,2*maxf-len);
    }
    for(int i=0;i<q;i++){
        cout<<ans[i]<<endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}