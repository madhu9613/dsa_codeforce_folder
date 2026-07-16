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

/*

«+» means this block has 4 doors (one door to each neighbouring block);
«-» means this block has 2 doors — to the left and to the right neighbours;
«|» means this block has 2 doors — to the top and to the bottom neighbours;
«^» means this block has 1 door — to the top neighbour;
«>» means this block has 1 door — to the right neighbour;
«<» means this block has 1 door — to the left neighbour;
«v» means this block has 1 door — to the bottom neighbour;
«L» means this block has 3 doors — to all neighbours except left one;
«R» means this block has 3 doors — to all neighbours except right one;
«U» means this block has 3 doors — to all neighbours except top one;
«D» means this block has 3 doors — to all neighbours except bottom one;
«*» means this block is a wall and has no doors.

*/


struct state{
int r,c,rot;
};
int n,m;
string grid[1005];
int dist[1005][1005][4];
int dr[]={-1,0,1,0}; // u,r,d,l
int dc[]={0,1,0,-1};
int get_mask(char c)
{
    if (c == '+')
        return 0b1111;
    if (c == '-')
        return 0b0101;
    if (c == '|')
        return 0b1010;
    if (c == '^')
        return 0b1000;
    if (c == '>')
        return 0b0100;
    if (c == 'v')
        return 0b0010;
    if (c == '<')
        return 0b0001;
    if (c == 'L')
        return 0b1110;
    if (c == 'R')
        return 0b1011;
    if (c == 'U')
        return 0b0111;
    if (c == 'D')
        return 0b1101;
    return 0b0000; // Wall '*'
}
int get_rotated(char c,int rot){
    int mask=get_mask(c);
    int shift=rot%4;
    return ((mask>>shift) | (mask<<(4-shift))) &0b1111;
}

bool has_door(int mask,int dir){
    return (mask &(1<<(3-dir)))!=0;
}
void solve() {
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>grid[i];
    }
    int sx,sy,tx,ty;
    cin>>sx>>sy>>tx>>ty;
    sx--;
    sy--;
    tx--;
    ty--;

    memset(dist,-1,sizeof(dist));

    queue<state>q;
    q.push({sx,sy,0});
    dist[sx][sy][0]=0;
    while(!q.empty()){
        state cur=q.front();
        q.pop();
        if(cur.r==tx && cur.c==ty){
            cout<<dist[cur.r][cur.c][cur.rot]<<endl;
            return ;
        }

        int cmask=get_rotated(grid[cur.r][cur.c],cur.rot);
        for(int d=0;d<4;d++){
            int nr=cur.r+dr[d];
            int nc=cur.c+dc[d];
            if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]!='*'){

                int nxtmask=get_rotated(grid[nr][nc],cur.rot);
                int opp_d=(d+2)%4;
                if(has_door(cmask,d) && has_door(nxtmask,opp_d)){
                    if(dist[nr][nc][cur.rot]==-1){
                        dist[nr][nc][cur.rot]=dist[cur.r][cur.c][cur.rot]+1;
                        q.push({nr,nc,cur.rot});
                        
                        
                    }
                }
            }
        }

        int nxt_rot=(cur.rot+1);
        if(dist[cur.r][cur.c][nxt_rot]==-1){
            dist[cur.r][cur.c][nxt_rot]=dist[cur.r][cur.c][cur.rot]+1;
            q.push({cur.r,cur.c,nxt_rot});
        }

    }

    cout<<-1<<endl;
  

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
   // precompute();
   // freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}