// https://codeforces.com/problemset/problem/1063/B

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define max3(a, b, c) max(max(a, b), c)
#define max4(a, b, c, d) max(max(a, b), max(c, d))
#define pii pair<int, int>
#define pll pair<ll, ll>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl '\n'

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}
ll pow(ll a,ll b,ll m)
{
if(b==0)
 return 1;
if(b==1) return a%m;
 ll temp=pow(a,b/2,m);
 if(b%2==0)
 {
 return (temp*temp)%m;
}
else
{
return (a*(temp*temp)%m)%m ;
}
}

const int MOD = 1e9 + 7;
const int INF = INT_MAX;
const ll LINF = 1e18;

const int MAXN = 40005;


void solve() {

    int n, m;
    cin >> n >> m;

    int sr, sc;
    cin >> sr >> sc;
    sr--, sc--;

    int x, y;
    cin >> x >> y;
    int dx[4]={0,0,-1,1};
    int dy[4]={1,-1,0,0};

    vector<string> grid(n);
    for (int i = 0; i < n; i++)
        cin >> grid[i];

    vector<vector<int>> dist(n, vector<int>(m, INF));
    deque<pair<int, int>> dq;

    dist[sr][sc] = 0;
    dq.push_front({sr, sc});

    while (!dq.empty())
    {
        auto [r, c] = dq.front();
        dq.pop_front();

        for (int d = 0; d < 4; d++)
        {
            int nr = r + dx[d];
            int nc = c + dy[d];

            if (nr < 0 || nr >= n || nc < 0 || nc >= m)
                continue;
            if (grid[nr][nc] == '*')
                continue;

            int newleft = dist[r][c] + (dy[d] == -1);
            int newright = (nc - sc) + newleft;

            if (newleft > x || newright > y)
                continue;

            if (newleft < dist[nr][nc])
            {
                dist[nr][nc] = newleft;
                if (dy[d] == -1)
                    dq.push_back({nr, nc}); 
                else
                    dq.push_front({nr, nc}); 
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (dist[i][j] == INF)
                continue;
            int right = (j - sc) + dist[i][j];
            if (dist[i][j] <= x && right <= y)
                ans++;
        }
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
 
    while (t--)
        solve();

    return 0;
}