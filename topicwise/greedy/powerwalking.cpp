// minimum sum of strengths of a team of k
//  children Sam can get.

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

void solve()
{
    int n;
    cin >> n;
    vi a(n);
    unordered_map<int, int> freq;

    int uni = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];

        if (freq[a[i]] == 0)
        {
            uni++;
        }
        freq[a[i]]++;
    }

    for (int k = 1; k <= n; k++)
    {
        cout << max(k, uni)<<" ";
    }cout<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
