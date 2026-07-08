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

ll fact[MAXN], invFact[MAXN];
void precompute() {
    fact[0] = 1;
    invFact[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    invFact[MAXN - 1] = modinv(fact[MAXN - 1]);
    for (int i = MAXN - 2; i >= 1; i--) {
        invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
    }
}

ll nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
}

vector<int> primes;
bool isPrime[MAXN];
void sieve(int n) {
    fill(isPrime, isPrime + n + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) isPrime[j] = false;
        }
    }
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) primes.push_back(i);
    }
}

int phi[MAXN];
void sievePhi(int n) {
    for (int i = 0; i <= n; i++) phi[i] = i;
    for (int i = 2; i <= n; i++) {
        if (phi[i] == i) {
            for (int j = i; j <= n; j += i) {
                phi[j] -= phi[j] / i;
            }
        }
    }
}

using Matrix = vector<vector<ll>>;
Matrix matMul(Matrix A, Matrix B) {
    int rA = A.size(), cA = A[0].size(), cB = B[0].size();
    Matrix C(rA, vector<ll>(cB, 0));
    for (int i = 0; i < rA; i++) {
        for (int k = 0; k < cA; k++) {
            for (int j = 0; j < cB; j++) {
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
            }
        }
    }
    return C;
}

Matrix matPow(Matrix A, ll p) {
    int n = A.size();
    Matrix res(n, vector<ll>(n, 0));
    for (int i = 0; i < n; i++) res[i][i] = 1;
    while (p > 0) {
        if (p & 1) res = matMul(res, A);
        A = matMul(A, A);
        p >>= 1;
    }
    return res;
}

struct state
{
    int r,c,mask,dist;
};

int n,m;
string grid[20];
int objR[8],objC[8],objVal[8],T=0;
int dist[20][20][256];
bool isBomb[8];
bool crosses(int r, int c, int nr, int nc, int i)
{
    if (c == nc && c > objC[i])
    {
        if ((r == objR[i] && nr == objR[i] + 1) ||
            (r == objR[i] + 1 && nr == objR[i]))
        {
            return true;
        }
    }
    return false;
}

void solve() {

    cin>>n>>m;
    int sr,sc;
    vector<pair<int, int>> treasure_pos;
    for(int i=0;i<n;i++){
        cin>>grid[i];
        for(int j=0;j<m;j++){
            if(grid[i][j]=='S'){
                sr=i;
                sc=j;
            }else if(grid[i][j]=='B'){
                objR[T]=i;
                objC[T]=j;
                isBomb[T]=true;
                T++;
            }else if(grid[i][j]>='1' && grid[i][j]<='8'){
                objR[T]=i;
                objC[T]=j;
                isBomb[T]=false;
                treasure_pos.push_back({grid[i][j]-'0',T});
                T++;
            }

        }
    }
    vi prices(9);
    for(int i=1;i<=8;i++){
        prices[i]=0;
    }
    int num_t = treasure_pos.size();
    for(int i=1;i<=num_t;i++){
        int p;cin>>p;
        for(auto &t:treasure_pos){
            if(t.first==i){
                objVal[t.second]=p;
            }
        }
    }
    memset(dist,-1,sizeof(dist));
    queue<state>q;
    q.push({sr,sc,0,0});
    dist[sr][sc][0]=0;
    int dr[]={0,0,1,-1} ,dc[]={1,-1,0,0};
    int max_prof=0;
    while(!q.empty()){
        state cur=q.front();
        q.pop();
        for(int d=0;d<4;d++){
            int nr=cur.r+dr[d],nc=cur.c+dc[d];
            if(nr<0 || nr>=n || nc<0 || nc>=m ){
                continue;
            }

            if (nr < 0 || nr >= n || nc < 0 || nc >= m || grid[nr][nc] == '#' ||
                grid[nr][nc] == 'B' || (grid[nr][nc] >= '1' && grid[nr][nc] <= '8'))
              {
                continue;
              }

              int nmask=cur.mask;
              for(int obj=0;obj<T;obj++){
                  if (crosses(cur.r, cur.c, nr, nc, obj))
                  {
                    nmask^=(1<<obj);
                  }
              }

              if(nr==sr && nc==sc){
                int profit=-(cur.dist+1);
                int bomb_inside=false;
                for(int obj=0;obj<T;obj++){
                    if((nmask>>obj)&1){
                        //if its bit is 1 its inside;
                        if(isBomb[obj]){
                            bomb_inside=true;
                         
                        }
                        else{
                            profit+=objVal[obj];
                        }
                    }

                }
                if(!bomb_inside){

                    max_prof=max(max_prof,profit);

                }

              }else if(dist[nr][nc][nmask]==-1){
                dist[nr][nc][nmask]=cur.dist+1;
                q.push({nr,nc,nmask,cur.dist+1});
              }

        }
    }

    cout<<max_prof<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
   // precompute();
    int t = 1;
    while (t--) solve();
    return 0;
}