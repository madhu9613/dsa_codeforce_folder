// Author: Madhujya Rajkhowa
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define all(x) (x).begin(), (x).end()
#define endl '\n'

const int MOD = 1e9 + 7;
const int INF = INT_MAX;

void solve()
{
    int n;
    cin >> n;
    vll a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vll Maxbits(31, 0);  // reset for each test case

    for (int i = 0; i < n; i++)
    {
        for (int bit = 30; bit >= 0; bit--)
        {
            if (a[i] & (1 << bit))
            {
                Maxbits[bit]++;
                break;
            }
        }
    }

    ll ans = 0;
    for (int bit = 0; bit <= 30; bit++)
    {
        ans += Maxbits[bit] * (Maxbits[bit] - 1) / 2;
    }
    cout << ans << endl;
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
