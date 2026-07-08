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

const int MAXN=21;
const int MAXM=4005;
const int MAXH=405;
int n,m,p_p;
double p;

int h[MAXN];

double f[MAXM][MAXM]; // after i round j failure occure;

double g[MAXM][MAXN][MAXH];

void solve() {
    cin>>n>>m>>p_p;
    p=p_p/100.0;

    int min_h=INT_MAX;

    for(int i=0;i<n;i++){
        cin>>h[i];
        h[i]--;
        min_h=min(min_h,h[i]);
    }
    int s=0;
    for(int i=0;i<n;i++){
        s+=(h[i]-min_h);
    }
    if(s>m){
        cout<<"0.000000"<<endl;
        return;
    }
    memset(f,0,sizeof(f));
    f[0][0]=1.0;
    for(int i=0;i<m;i++){
        for(int j=0;j<=s;j++){
            if(f[i][j]==0){
                continue;

            }
            f[i+1][j]+=f[i][j]*p;
            if(j+1<=s){
                f[i+1][j+1]+=f[i][j]*(1-p);
            }
        }
    }

    memset(g,0,sizeof(g));
    g[0][0][0]=1.0;
    for(int i=1;i<=m;i++){
        
        g[i][0][0]=1.0;

        for(int x=1;x<=min(i,min_h);x++){
            double shine=g[i-1][0][x-1]*p;
            double fail=max(
                g[i-1][0][x],
                g[i-1][n-1][x-1]
            )*(1-p);

            g[i][0][x]=shine+fail;
        }


        for(int c=1;c<n;c++){
            g[i][c][0]=g[i-1][c][0]*p+g[i-1][c-1][0]*(1-p);

            for(int x=1;x<=min(i,min_h);x++){
                g[i][c][x]=g[i-1][c][x-1]*p+g[i-1][c-1][x]*(1-p);
            }
        }


    }

    double ans=0;
    for(int i=s;i<=m;i++){
        double best=0;
        for(int x=0;x<=min(m-i,min_h);x++){
            best=max(best,g[m-i][0][min_h-x]);
        }

        ans+=f[i][s]*best;
    }
    
    cout<<fixed<<setprecision(6)<<ans<<endl;
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}