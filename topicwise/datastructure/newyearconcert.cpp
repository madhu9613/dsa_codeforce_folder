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
struct SegTree
{
    int n;
    vector<int> t;

    SegTree(const vector<int> &a)
    {
        n = a.size();
        t.resize(4 * n);
        build(1, 0, n - 1, a);
    }

    void build(int v, int l, int r, const vector<int> &a)
    {
        if (l == r)
        {
            t[v] = a[l];
            return;
        }
        int m = (l + r) / 2;
        build(v * 2, l, m, a);
        build(v * 2 + 1, m + 1, r, a);
        t[v] = gcd(t[v * 2], t[v * 2 + 1]);
    }

    int query(int v, int l, int r, int ql, int qr)
    {
        if (ql > r || qr < l)
            return 0;
        if (ql <= l && r <= qr)
            return t[v];
        int m = (l + r) / 2;
        return gcd(
            query(v * 2, l, m, ql, qr),
            query(v * 2 + 1, m + 1, r, ql, qr));
    }

    int query(int l, int r)
    {
        return query(1, 0, n - 1, l, r);
    }
};
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    SegTree st(a);

    vector<vector<int>> bad(n);

    // find all bad segments
    for (int l = 0; l < n; l++)
    {
        int low = l, high = n - 1;
        int best = l - 1;

        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (st.query(l, mid) >= mid - l + 1)
            {
                best = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        if (best >= l && st.query(l, best) == best - l + 1)
        {
            bad[best].push_back(l);
        }
    }

    int ans = 0, last = -1;
    for (int r = 0; r < n; r++)
    {
        for (int l : bad[r])
        {
            if (l > last)
            {
                ans++;
                last = r;
            }
        }
        cout << ans << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while (t--)
        solve();

    return 0;
}