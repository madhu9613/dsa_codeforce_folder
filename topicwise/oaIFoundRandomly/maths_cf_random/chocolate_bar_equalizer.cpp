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

tuple<int,int,int> get_fators(ll val){
    int x=0; //2^x;
    int y=0; //2^y;
    int rem=val; //rest;
    while(rem%2==0){
        x++;
        rem/=2;
    }
    while(rem%3==0){
        y++;
        rem/=3;
    }
    return {x,y,rem};
}

void apply_2nd(ll &a,ll &b,ll k){
    while(k--){
        if(a%3==0){
            a=(a/3)*2;
        }else{
            b=(b/3)*2;
        }
    }
}

void apply_1st(ll &a,ll &b,ll k){
    while(k--){
        if(a%2==0){
            a/=2;
        }else{
            b/=2;
        }
    }
}
void solve() {
    ll a1,b1,a2,b2;cin>>a1>>b1>>a2>>b2;

    auto [x1, y1, k1] = get_fators(a1);
    auto [x2, y2, k2] = get_fators(b1);

    int X1=x1+x2;
    int Y1=y1+y2;
    ll K1=k1*k2;

    auto [x3, y3, k3] = get_fators(a2);
    auto [x4, y4, k4] = get_fators(b2);
    int X2=x3+x4;
    int Y2=y3+y4;
    int K2=k3*k4;
    if(K1!=K2){
        cout<<-1<<endl;
        return;
    }

    // 1/3 rd operation;
    int min_y=min(Y1,Y2);
    int ny1=Y1-min_y;
    int ny2=Y2-min_y;


    // for half ops;
    int nx1=X1+ny1;
    int nx2=X2+ny2;
    int min_x=min(nx1,nx2);
    nx1-=min_x;
    nx2-=min_x;

    apply_2nd(a1,b1,ny1);
    apply_2nd(a2,b2,ny2);
    apply_1st(a1,b1,nx1);
    apply_1st(a2,b2,nx2);

    int t=nx1+nx2+ny1+ny2;

    cout<<t<<endl;

    cout<<a1<<" "<<b1<<endl;
    cout<<a2<<" "<<b2<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}