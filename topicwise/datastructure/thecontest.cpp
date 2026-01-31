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
void solve()
{
    int k1, k2, k3;
    cin >> k1 >> k2 >> k3;
    int n = k1 + k2 + k3;

    vector<int> c1(n + 1, 0), c2(n + 1, 0), c3(n + 1, 0);

    for (int i = 0; i < k1; i++)
    {
        int x;
        cin >> x;
        c1[x] = 1;
    }
    for (int i = 0; i < k2; i++)
    {
        int x;
        cin >> x;
        c2[x] = 1;
    }
    for (int i = 0; i < k3; i++)
    {
        int x;
        cin >> x;
        c3[x] = 1;
    }

    int p1 = 0, p2 = 0, p3 = 0;

    int besta = 0; // a[0]
    int best = 0;  // besta + b[0]

    for (int i = 1; i <= n; i++)
    {
        p1 += c1[i];
        p2 += c2[i];
        p3 += c3[i];

        int ai = p1 - p2;
        int bi = p2 - p3;

        best = max(best, besta + bi);
        besta = max(besta, ai);
    }

    int maxCorrect = best + p3;
    cout << n - maxCorrect << endl;
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