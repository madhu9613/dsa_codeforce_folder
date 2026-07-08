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
// here we need to two satisfy two distance condition and need to use minimum edges;

const int MAXN=3005;
vi adj[MAXN];
int dist[MAXN][MAXN];

void solve() {
    int n,m;cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int s1,t1,l1;
    int s2,t2,l2;cin>>s1>>t1>>l1>>s2>>t2>>l2;
    for(int i=1;i<=n;i++){
        fill(dist[i],dist[i]+n+1,INT_MAX);
        queue<int>q;
        q.push(i);
        dist[i][i]=0;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(int v:adj[u]){
                if(dist[i][v]>dist[i][u]+1){
                    dist[i][v]=dist[i][u]+1;
                    q.push(v);
                }
            }
        }

    }

        if(dist[s1][t1]>l1 || dist[s2][t2]>l2){
            cout<<-1<<endl;
            return ;
        }

        int ans=dist[s1][t1]+dist[s2][t2];
        for(int u=1;u<=n;u++){
            for(int v=1;v<=n;v++){
                int d=dist[u][v];
                int path1=dist[s1][u]+d+dist[v][t1];
                int path2=dist[s2][u]+d+dist[v][t2];
                if(path1<=l1 && path2<=l2){
                    ans=min(ans,path1+path2-d);
                }

                path2=dist[s2][v]+d+dist[u][t2];
                if(path1<=l1 && path2<=l2){
                    ans=min(ans,path1+path2-d);
                }

            }
        }

        cout<<m-ans<<endl;

    }


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}