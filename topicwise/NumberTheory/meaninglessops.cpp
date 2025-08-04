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
ll a;
cin>>a;
// i need msb;
ll msb=63-__builtin_clz(a);
ll largest=(1<<(msb+1))-1;
if(a!=largest)
{
    cout<<largest<<endl;
}
else {
    ll best = 1;
    for (ll i = 1; i * i <= a; i++) {
        if (a % i == 0) {
            if (i != a) best = max(best, i);
            if ((a / i) != a) best = max(best, a / i);
        }
    }
    cout << best << endl;
}

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}