#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define max3(a, b, c) max(max(a, b), c)
#define max4(a, b, c, d) max(max(a, b), max(c, d))
#define pii pair<int,int>
#define all(x) (x).begin(), (x).end()
#define endl '\n'

ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}

const int MOD = 1e9 + 7;
const int INF = INT_MAX;

void solve() {
    int n, k;
    cin >> n >> k;
    vi price(k); 
    for (int i = 0; i < k; i++) {
        cin >> price[i];
    }

    const ll INF = 1e18;
    vector<vector<ll>> dp(n + 1, vector<ll>(k + 1, INF));
    dp[0][0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            dp[i][j] = dp[i - 1][j];
            for (int s = 1; s <= k; s++) {
                if (price[s - 1] != -1 && j >= s && dp[i - 1][j - s] != INF) {
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - s] + price[s - 1]);
                }
            }
        }
    }

    ll ans = INF;
    for (int i = 1; i <= n; i++) {
        ans = min(ans, dp[i][k]);
    }

    cout << (ans == INF ? -1 : ans) << endl;
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
