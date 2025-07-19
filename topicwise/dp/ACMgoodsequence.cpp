//here good sequence is if bi is divided by b(i+1) means next numer
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
int dp[2005][2005];
void solve() {
    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= n; ++i) {
        dp[i][1] = 1;
    }
    vector<int> divisors[n+1];

      for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; j += i) {
            divisors[j].push_back(i);
        }
    }

    // Build sequences from length 2 to k
   for (int len = 2; len <= k; ++len) {
        for (int i = 1; i <= n; ++i) {
            for (int x : divisors[i]) {
                dp[i][len] = (dp[i][len] + dp[x][len - 1]) % MOD;
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans = (ans + dp[i][k]) % MOD;
    }

    cout << ans << endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    while (t--) solve();
    return 0;
}