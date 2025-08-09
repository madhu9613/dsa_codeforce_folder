#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
 
const int MAXN = 2e5 + 5;
 
int n;
vll arr, res;
vector<vi> gr;
 
void solve(int v, int p, ll mini, ll maxi) {
    res[v] = max(arr[v], arr[v] - mini);
    mini = min(arr[v], arr[v] - maxi);
 
    for (int u : gr[v]) {
        if (u == p) continue;
        solve(u, v, mini, res[v]);
    }
}
 
void run_case() {
    cin >> n;
    arr.resize(n);
    res.resize(n);
    gr.assign(n, {});
 
    for (int i = 0; i < n; ++i) cin >> arr[i];
 
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        gr[u].pb(v);
        gr[v].pb(u);
    }
 
    solve(0, -1, 0, 0);
 
    for (ll x : res) cout << x << " ";
    cout << '\n';
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
    while (t--) run_case();
 
    return 0;
}