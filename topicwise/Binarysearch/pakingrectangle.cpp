#include <bits/stdc++.h>
using namespace std;

#define ll long long

int w,h,n;

bool ispos(ll a)
{
    ll onelayer = a / min(w,h);
    if (onelayer == 0) return false;
    ll total_layer_needed = (n + onelayer - 1) / onelayer;
    return total_layer_needed * max(w,h) <= a;
}

void solve() {
    cin >> w >> h >> n;
    ll l = 1, r = 1LL * max(w,h) * n;
    ll ans = -1;
    while (l <= r)
    {
        ll m = l + (r - l) / 2;
        if (ispos(m))
        {
            ans = m;
            r = m - 1;
        }
        else
        {
            l = m + 1;
        }
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
