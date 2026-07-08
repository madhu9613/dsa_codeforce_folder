#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;

const int MOD = 1000000007;

vll a;

ll merge_count(int l, int r)
{
    if (l >= r)
        return 0;

    int mid = (l + r) / 2;

    ll inv = merge_count(l, mid) + merge_count(mid + 1, r);

    vector<ll> temp;
    temp.reserve(r - l + 1);

    int i = l, j = mid + 1;

    while (i <= mid && j <= r)
    {
        if (a[i] <= a[j])
        {
            temp.push_back(a[i]);
            i++;
        }
        else
        {
            // a[i] > a[j]
            inv += (mid - i + 1);
            temp.push_back(a[j]);
            j++;
        }
    }

    while (i <= mid)
        temp.push_back(a[i++]);

    while (j <= r)
        temp.push_back(a[j++]);

    for (int k = 0; k < (int)temp.size(); k++)
        a[l + k] = temp[k];

    return inv;
}

void solve()
{
    int n;
    cin >> n;

    a.resize(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << merge_count(0, n - 1) << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
        solve();

    return 0;
}