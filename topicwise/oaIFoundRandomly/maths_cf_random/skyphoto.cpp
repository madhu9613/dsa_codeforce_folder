#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define vi vector<int>
#define vll vector<ll>
#define vpi vector<pii>
#define vpll vector<pll>

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

const ll INF = 1e18;
const int MOD = 1000000007;

// Fast exponentiation (a^b % mod)
ll modpow(ll a, ll b, ll mod = MOD)
{
    ll res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

ll modinv(ll a, ll mod = MOD)
{
    return modpow(a, mod - 2, mod);
}

// GCD
ll gcd(ll a, ll b)
{
    return b ? gcd(b, a % b) : a;
}

// LCM
ll lcm(ll a, ll b)
{
    return a / gcd(a, b) * b;
}

// void solve() {
//     int n;cin>>n;
//     vll h(n+1),b(n+1);
//     for(int i=1;i<=n;i++){
//         cin>>h[i];
//     }
//     for(int i=1;i<=n;i++){
//         cin>>b[i];
//     }
//     vll dp(n+1,0);
//     stack<pair<int,ll>>s;
//     for(int i=1;i<=n;i++){
//         ll  max_dp=dp[i-1];
//         while(!s.empty() && h[s.top().first]>h[i]){
//             max_dp=max(max_dp,s.top().second);
//             s.pop();
//         }
//         ll op1=max_dp+b[i];
//         ll op2=-1e18;
//         if(!s.empty()){
//             int Li=s.top().first;
//             op2=dp[Li];
//         }
//         dp[i]=max(op1,op2);
//         s.push({i,max_dp});
//     }

//     cout<<dp[n]<<endl;

// }

struct segtree
{
    int n;
    vll tree;
    segtree(int n)
    {
        this->n = n;
        tree.assign(4 * n, -INF);
    }
    void update(int node, int l, int r, int idx, ll val)
    {
        if (l == r)
        {
            tree[node] = max(tree[node], val);
            return;
        }
        int mid = (l + r) / 2;
        if (idx <= mid)
        {
            update(2 * node, l, mid, idx, val);
        }
        else
        {
            update(2 * node + 1, mid + 1, r, idx, val);
        }
        tree[node] = max(tree[2 * node], tree[2 * node + 1]);
    }

    void update(int idx,ll val){
        update(1,0,n,idx,val);
    }


    // l---r
    ll query(int node, int l, int r, int ql, int qr)
    {
        if (qr < l || ql > r)
        {
            return -INF;
        }
        if (ql <= l && r <= qr)
        {
            return tree[node];
        }
        int mid = (l + r) / 2;
        return max(query(2 * node, l, mid, ql, qr), query(2 * node + 1, mid + 1, r, ql, qr));
    }

    ll query(int ql,int qr){
        return query(1,0,n,ql,qr);
    }


};
void solve()
{

    int n;
    cin >> n;
    vll h(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> h[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }

    vi L(n + 1, 0);
    for (int i = 2; i <= n; i++)
    {
        L[i] = i - 1;
        while (L[i] > 0 && h[L[i]] >= h[i])
        {
            L[i] = L[L[i]];
        }
    }

    vll dp(n+1,0);
    segtree st(n+1);
    //dp[0]=0;
    st.update(0,0);
    for(int i=1;i<=n;i++){
        ll max_dp=st.query(L[i],i-1);
        ll op1=max_dp+b[i];

        ll op2=-INF;
        if(L[i]>0){
            op2=dp[L[i]];
        }

        dp[i]=max(op1,op2);
        st.update(i,dp[i]);
    }

    cout<<dp[n]<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--)
        solve();

    return 0;
}