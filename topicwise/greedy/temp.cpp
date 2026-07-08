#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve()
{
    ll n;
    int k, q;
    cin >> n >> k >> q;

    vector<ll> a(k + 1), b(k + 1);

    a[0] = 0;
    b[0] = 0;

    for (int i = 1; i <= k; i++)
        cin >> a[i];
    for (int i = 1; i <= k; i++)
        cin >> b[i];

    while (q--)
    {
        ll d;
        cin >> d;

        // find i such that a[i-1] <= d <= a[i]
        int i = lower_bound(a.begin(), a.end(), d) - a.begin();

        if (a[i] == d)
        {
            cout << b[i] << " ";
            continue;
        }

        // segment: i-1 → i
        ll dist = d - a[i - 1];
        ll total_dist = a[i] - a[i - 1];
        ll total_time = b[i] - b[i - 1];

        ll time = b[i - 1] + (dist * total_time) / total_dist;

        cout << time << " ";
    }

    cout << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        solve();
}