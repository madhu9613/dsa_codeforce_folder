#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;

    cout << "digit" << endl;
    int x;
    cin >> x;

    cout << "digit" << endl;
    cin >> x;

    for (int i = 8; i >= 1; i /= 2)
    {
        cout << "add " << -i << endl;
        cin >> x;
    }

    cout << "add " << n - 1 << endl;
    cin >> x;

    cout << "!" << endl;
    cin >> x;
    assert(x == 1);
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}