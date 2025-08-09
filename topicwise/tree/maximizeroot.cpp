#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define max3(a, b, c) max(max(a, b), c)
#define max4(a, b, c, d) max(max(a, b), max(c, d))
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()
#define endl '\n'

const int INF = 1e9 + 1;

int n;
vector<vi> adj;
vi a;

bool dfs(int u,int x)
{
    if(x>INF) return false;

    bool isleaf=true;
    if(u!=1) x+=max(0,x-a[u]);
    for(int v:adj[u])
    {
        isleaf=false;
        if(!dfs(v,x))  return false;
    }

    return (!isleaf  || x<=a[u]);

}

void solve() {
    cin >> n;

    a.assign(n + 1, 0);
    adj.assign(n + 1, {});

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    for (int i = 2; i <= n; ++i) {
        int p;
        cin >> p;
        adj[p].pb(i);
    }

    int l = 1, r = INF, ans = 0;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (dfs(1, mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << a[1] + ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}
