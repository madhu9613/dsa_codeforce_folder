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


ll b[11];// b[x]:total numbers with beauty x;
ll ncr[10][10];


ll p(ll n,int k){
    if(n<k){
        return 0;
    }
    ll res=1;
    for(int i=0;i<k;i++){
        res=(res*((n-i)%MOD))%MOD;
    }
    return res;
}
void f(){
for(int i=0;i<=6;i++){
    ncr[i][0]=1;
    for(int j=1;j<=i;j++){
        ncr[i][j]=(ncr[i-1][j-1]+ncr[i-1][j])%MOD;
    }
}
}
void solve() {
  ll m;cin>>m;
  string s=to_string(m);
  memset(b,0,sizeof(b));
  ll dp1[15][15][2]={0};
  dp1[0][0][1]=1; // till ith idx how much beauy count i have dp[i][c][t]
  int n=s.length();
  for(int i=0;i<n;i++){
    for(int c=0;c<=9;c++){
        for(int tight=0;tight<2;tight++){
            if(dp1[i][c][tight]==0){
                continue;
            }
            int limit=tight?(s[i]-'0'):9;
            for(int d=0;d<=limit;d++){
                int ntight=tight && (d==limit);
                int nc=c+((d==4 || d==7)?1:0);
                if(nc<=9){
                    dp1[i+1][nc][ntight]+=dp1[i][c][tight];
                }
            }

        }

    }
  }

  for(int k=0;k<=9;k++){
    b[k]=(dp1[n][k][0]+dp1[n][k][1]);
  }
  b[0]--; //as we use 1-m;

  ll total_ans=0;
  // total score of My team is S;
  for(int S=1;S<=9;S++){

    if(b[S]==0) continue;

    ll A[11];

    for(int i=0;i<=9;i++){
        A[i]=b[i];
    }

    A[S]--;

    // dp[i][s]=ways to assign (i) parties so thhat there total score combine is s;

    ll dp[7][10]={0};

    dp[0][0]=1;
    for(int k=0;k<=9;k++){

        ll ndp[7][10]={0};
        for(int i=0;i<=6;i++){
            for(int s=0;s<S;s++){

                if (dp[i][s] == 0)
                    continue;
                for (int c = 0; c <= 6 - i; c++)
                {
                    if(s+c*k>=S){
                        break;
                    }

                    ll ways=dp[i][s]*ncr[6-i][c]%MOD;
                    ways=ways*p(A[k],c)%MOD; // out of aval perutaion it among c person or parties;

                    ndp[i+c][s+c*k]=(ndp[i+c][s+c*k]+ways)%MOD;


                }
            }

        }


        // copy ndp to dp;
        for(int i=0;i<=6;i++){
            for(int s=0;s<S;s++){
                dp[i][s]=ndp[i][s];
            }
        }

      
    }

    ll others = 0;
    for (int s = 0; s < S; s++)
    {
        others = (others + dp[6][s]) % MOD;
    }

    ll total = (b[S] % MOD) * others % MOD;
    total_ans = (total_ans + total) % MOD;
  }

  cout<<total_ans<<endl;



}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
        f();
    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}