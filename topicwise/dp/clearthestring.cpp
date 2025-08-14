#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for(int len = 1; len <= n; len++){
        for(int l = 0; l + len - 1 < n; l++){
            int r = l + len - 1;
            if(l == r) dp[l][r] = 1;
            else{
                dp[l][r] = 1 + dp[l+1][r];  
                for(int m = l+1; m <= r; m++){
                    if(s[l] == s[m]){
                        int mid = (m-1 >= l+1 ? dp[l+1][m-1] : 0);
                        dp[l][r] = min(dp[l][r], mid + dp[m][r]);
                    }
                }
            }
        }
    }

    cout << dp[0][n-1] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    while(t--) solve();
    return 0;
}
