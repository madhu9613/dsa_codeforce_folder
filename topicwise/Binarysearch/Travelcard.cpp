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
int n;cin>>n;
vi t(n);for(int i=0;i<n;i++) cin>>t[i];
vi dp(n),ans(n);
for(int i=0;i<n;++i)
{
    dp[i]=(i>0?dp[i-1]:0)+20;

    int j=lower_bound(all(t),t[i]-89)-t.begin();

    int cost90=(j>0?dp[j-1]:0)+50;
    dp[i]=min(dp[i],cost90);

    j=lower_bound(all(t),t[i]-1439)-t.begin();
    int cost1440=(j>0?dp[j-1]:0)+120;
    dp[i]=min(dp[i],cost1440);

    ans[i]=dp[i]-(i>0?dp[i-1]:0);
    cout<<ans[i]<<endl;

}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    while (t--) solve();
    return 0;
}