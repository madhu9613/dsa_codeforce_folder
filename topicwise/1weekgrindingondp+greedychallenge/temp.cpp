#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s1, s2;
    cin >> s1 >> s2;

    // Step 1: check compatibility
    if (s1 + s2 != s2 + s1)
    {
        cout << 0 << '\n';
        return 0;
    }

    int n = s1.size();
    int m = s2.size();

    int g = __gcd(n, m);

    int ans = 0;

    // Step 2: check all divisors of g
    for (int len = 1; len <= g; len++)
    {
        if (g % len != 0)
            continue;

        string d = s1.substr(0, len);

        bool ok = true;

        // check s1
        for (int i = 0; i < n; i++)
        {
            if (s1[i] != d[i % len])
            {
                ok = false;
                break;
            }
        }

        // check s2
        for (int i = 0; i < m && ok; i++)
        {
            if (s2[i] != d[i % len])
            {
                ok = false;
                break;
            }
        }

        if (ok)
            ans++;
    }

    cout << ans << '\n';
}