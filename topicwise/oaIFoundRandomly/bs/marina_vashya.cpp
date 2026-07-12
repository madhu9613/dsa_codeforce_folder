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

char get_diff(char c1, char c2){
    for(char ch='a';ch<'z';ch++){
        if(ch!=c1 && ch!=c2){
            return ch;
        }
    }
    return 'a';
}
void solve() {

    int n,t;
    cin>>n>>t;
    string a,b;
    cin>>a;
    cin>>b;
    // lets calculate d=f(a,b);
    int d=0;
    string res(n,' ');
   
    for(int i=0;i<n;i++){
        if(a[i]!=b[i]){
            d++;
        }
    }
    if(t<(d+1)/2){
        cout<<-1<<endl;
        return;
    }

    // i want t pair to be mismatched 
    int k=n-t;
    int rem1=k,rem2=k;
    for(int i=0;i<n;i++){
        if(a[i]==b[i]){
            if(rem1>0 && rem2>0){
                rem1--;
                rem2--;
                res[i]=a[i];
            }
            else{
                res[i]=get_diff(a[i],b[i]);
            }
        }
    }

    for(int i=0;i<n;i++){
        if(a[i]!=b[i]){
            if(rem1>0){
                res[i]=a[i];
                rem1--;
            }
            else if(rem2>0){
                res[i]=b[i];
                rem2--;
            }
            else{
                res[i]=get_diff(a[i],b[i]);
            }

        }
    }

    cout<<res<<endl;

    
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