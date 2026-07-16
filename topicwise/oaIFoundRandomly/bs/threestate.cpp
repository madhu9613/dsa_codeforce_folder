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

const ll INF = 1e9;
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

int n,m;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
void bfs(const vector<string>&grid,vector<vector<int>>&dist,char state){
    queue<pair<int,int>>q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==state){
                dist[i][j]=0;
                q.push({i,j});
            }
        }
    }
    while(!q.empty()){
        auto [x,y]=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny]!='#'){
                int cost=(grid[nx][ny]=='.')?1:0;
                if(dist[nx][ny]>dist[x][y]+cost){
                    dist[nx][ny]=dist[x][y]+cost;
                    q.push({nx,ny});
                }
            }
        }
    }
}
void solve() {

    cin>>n>>m;
    vector<string>grid(n);
    for(int i=0;i<n;i++){
        cin>>grid[i];
    }
    vector<vi>d1(n,vi(m,INF)),d2(d1),d3(d1);
    bfs(grid,d1,'1');
    bfs(grid,d2,'2');
    bfs(grid,d3,'1');

    int ans=INF;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(d1[i][j]==INF || d2[i][j]==INF || d3[i][j]==INF){
                continue;
            }
            int csum=d1[i][j]+d2[i][j]+d3[i][j];
            if(grid[i][j]=='.'){
                csum-=2;
            }
            ans=min(ans,csum);
        }
    }

    cout<<(ans==INF?-1:ans)<<endl;



    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
   // precompute();
   // freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}