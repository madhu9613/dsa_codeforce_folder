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

ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}
const int MOD = 1e9 + 7;
const int INF = INT_MAX;
struct DSU
{
    vector<int> parent, rank;
    DSU(int n)
    {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for (int i = 1; i <= n; i++)
            parent[i] = i;
    }
    int find(int x)
    {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }
    bool unite(int x, int y)
    {
        int px = find(x);
        int py = find(y);
        if (px == py)
            return false;
        if (rank[px] < rank[py])
            swap(px, py);
        parent[py] = px;
        if (rank[px] == rank[py])
            rank[px]++;
        return true;
    }
};

void solve()
{
    int n;
    cin >> n;
    DSU dsu(n);
    vector<pii>red,edges(n-1);
    for(int i=0;i<n-1;i++)
    {
        int a,b;cin>>a>>b;
        edges[i]={a,b};
        if(!dsu.unite(a,b)){
            red.pb({a,b});
        }
    }

    vi reps;
    for(int i=1;i<=n;i++){
        if(dsu.find(i)==i) reps.pb(i);
    }

    int t=(int)reps.size()-1;
    cout<<t<<endl;
    for(int i=0;i<t;i++)
    {
        cout<<red[i].first<<" "<<red[i].second<<" "<<reps[i]<<" "<<reps[i+1]<<endl;
    }

}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    while (t--)
        solve();
    return 0;
}