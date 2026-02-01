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

struct node{
ll val;
int left,right;
};
vector<node>tree;
ll cnt=0;
unordered_set<ll> good;

void dfs(int u, ll low, ll high)
{
    if (u == -1)
        return;

    ll v = tree[u].val;

    if (v >= low && v <= high)
        good.insert(v);

    dfs(tree[u].left, low, min(high, v));
    dfs(tree[u].right, max(low, v), high);
}

void solve()
{
    int n;
    cin >> n;

    tree.resize(n + 1);
    vector<bool> ischild(n + 1, false);

    for (int i = 1; i <= n; i++)
    {
        cin >> tree[i].val >> tree[i].left >> tree[i].right;
        if (tree[i].left != -1)
            ischild[tree[i].left] = true;
        if (tree[i].right != -1)
            ischild[tree[i].right] = true;
    }

    int root = -1;
    for (int i = 1; i <= n; i++)
        if (!ischild[i])
            root = i;

    good.clear();
    dfs(root, LLONG_MIN, LLONG_MAX);

    ll cnt = 0;
    for (int i = 1; i <= n; i++)
        if (!good.count(tree[i].val))
            cnt++;

    cout << cnt << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    
    while (t--)
        solve();

    return 0;
}