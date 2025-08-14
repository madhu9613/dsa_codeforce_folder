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

//ispal[i][j]=>is subtring (i..j) pallindrom;
//dp[i][j]=>no of substring in (i..j) which are pallindrom;
const int MAXN=5005;
bool ispal[MAXN][MAXN];
int dp[MAXN][MAXN];

void solve() {
 string s;
    cin >> s;
    s = " " + s; 
    int n = s.length() - 1; 

    for(int i = 1; i <= n; i++) ispal[i][i] = true;
    for(int i = 1; i < n; i++) if(s[i] == s[i+1]) ispal[i][i+1] = true;

    for(int len = 3; len <= n; len++) {
        for(int i = 1; i <= n - len + 1; i++) {
            int j = i + len - 1;
            if(s[i] == s[j] && ispal[i+1][j-1]) ispal[i][j] = true;
        }
    }

    for(int len = 1; len <= n; len++) {
        for(int i = 1; i <= n - len + 1; i++) {
            int j = i + len - 1;
            if(len == 1) dp[i][j] = 1;
            else dp[i][j] = dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1] + (ispal[i][j] ? 1 : 0);
        }
    }

    int q;
    cin >> q;
    while(q--) {
        int l, r;
        cin >> l >> r;
        cout << dp[l][r] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;

    while (t--) solve();
    return 0;
}