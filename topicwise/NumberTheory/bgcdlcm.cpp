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
    ll k;
    cin >> k;

    set<pair<ll, ll>> s; // to avoid duplicate (a, b) pairs

    for (ll d = 1; d * d <= k; ++d) {
        if (k % d != 0) continue;

        for (ll div : {d, k / d}) {
            ll xy = k / div - 1;

            for (ll x = 1; x * x <= xy; ++x) {
                if (xy % x != 0) continue;
                ll y = xy / x;
                if (__gcd(x, y) == 1) {
                    ll a = div * x;
                    ll b = div * y;
                    s.insert({min(a, b), max(a, b)}); 
                }
            }
        }
    }

    cout << s.size() << endl;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
