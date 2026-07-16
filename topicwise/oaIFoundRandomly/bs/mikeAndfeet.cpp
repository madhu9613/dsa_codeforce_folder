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


void solve() {
    int n;
    cin>>n;
    vll a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vi left(n),right(n);
     stack<int>st;
     for(int i=0;i<n;i++){
        while(!st.empty() && a[st.top()]>=a[i]){
            st.pop();
        }
        left[i]=st.empty()?-1:st.top();
        st.push(i);
     }

     while(!st.empty()){
        st.pop();
     }
     for(int i=n-1;i>=0;i--){
        while(!st.empty() && a[st.top()]>=a[i]){
            st.pop();
        }
        right[i]=st.empty()?n:st.top();
        st.push(i);
     }
     vll ans(n+1,0);

     // for this i; smaller elemetn in L[i] and in right-> R[i]
     // valid range where is smallest [L[i]+1....R[i]-1]
     // R[i]-1-L[i]-1+1;

     for(int i=0;i<n;i++){
        int len=right[i]-left[i]-1;
        ans[len]=max(ans[len],a[i]);
     }
     // see if a can be max value for group of x then it can definatly be for x-1';

     for(int i=n-1;i>=1;i--){
        ans[i]=max(ans[i],ans[i+1]);
     }

     for(int i=1;i<=n;i++)
     {
        cout<<ans[i]<<" ";
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