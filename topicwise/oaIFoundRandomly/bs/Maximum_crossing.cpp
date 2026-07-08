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


vll a;
ll merge_count(int l,int r){
    
    if(l>=r){
        return 0;
    }
    int mid=(l+r)/2;
    //[l..mid] and [mid+1...r];

    ll count=merge_count(l,mid)+merge_count(mid+1,r);

    int i=l,j=mid+1;
    int len=r-l+1;


    vll temp;
    while(i<=mid && j<=r){
        if(a[i]<a[j]){
            temp.push_back(a[i]);
            i++;
        }
        else{
            // a[i]>=a[j]
            count+=(mid-i+1);
            temp.push_back(a[j]);
            j++;
        }
    }

    while(i<=mid){
        temp.push_back(a[i++]);
    }
    while(j<=r){
        temp.push_back(a[j++]);
    }

    for(int k=0;k<len;k++){
        a[l+k]=temp[k];
    }
    return count;
}
void solve() {
    int n;
    cin>>n;
    a.resize(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    cout<<merge_count(0,n-1)<<endl;

    // a crossing if a[i]>=a[j] for i<j similer to merge sort counting ;or use segtree;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
   // precompute();
   // freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);
    int t = 1;
    cin>>t;
    while (t--) solve();
    return 0;
}