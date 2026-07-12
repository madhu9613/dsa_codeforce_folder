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


struct state{
int cost,u,lastw;
bool operator>(const state&other) const{
    return cost>other.cost;
}
};
void solve() {
    
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>>adj(n+1);
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    vector<vector<int>>dist(n+1,vector<int>(51,INF));
    priority_queue<state,vector<state>,greater<state>>pq;
    dist[1][0]=0;
    pq.push({0,1,0});
    while(!pq.empty()){
        auto [d,u,last_w]=pq.top();
        pq.pop();
        if(d>dist[u][last_w]){
            continue;
        }
        if(last_w==0){
            for(auto &edge:adj[u]){
                int v=edge.first;
                int w=edge.second;
                if(dist[v][w]>d){
                    dist[v][w]=d;
                    pq.push({dist[v][w],v,w});
                }
            }
        }
        else{
            for(auto &edge:adj[u]){
                int v=edge.first;
                int w=edge.second;
                int cost=(last_w+w)*(last_w+w);
                if(dist[v][0]>d+cost){
                    dist[v][0]=d+cost;
                    pq.push({dist[v][0],v,0});
                }
            }
        }
    }

    for(int i=1;i<=n;i++){
        if(dist[i][0]==INF){
            cout<<-1<<" ";
        }
        else{
            cout<<dist[i][0]<<" ";
        }
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