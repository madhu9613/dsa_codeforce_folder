#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e7 + 1;
vector<int> spf(MAX); // smallest prime factor

// Sieve to fill smallest prime factor
void sieve() {
    for (int i = 2; i < MAX; ++i) {
        if (spf[i] == 0) {
            for (int j = i; j < MAX; j += i) {
                if (spf[j] == 0)
                    spf[j] = i;
            }
        }
    }
}

// Get distinct prime factors using SPF
vector<int> get_factors(int x) {
    vector<int> factors;
    while (x > 1) {
        int p = spf[x];
        factors.push_back(p);
        while (x % p == 0)
            x /= p;
    }
    return factors;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    sieve();

    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> res1(n, -1), res2(n, -1);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        vector<int> pf = get_factors(a[i]);
        if (pf.size() >= 2) {
            int p1 = pf[0];
            int p2 = pf[1];

            int d1 = 1;
            int temp = a[i];
            while (temp % p1 == 0) {
                d1 *= p1;
                temp /= p1;
            }
            int d2 = a[i] / d1;

            if (__gcd(d1 + d2, a[i]) == 1) {
                res1[i] = d1;
                res2[i] = d2;
            }
        }
    }

    for (int x : res1) cout << x << ' ';
    cout << '\n';
    for (int x : res2) cout << x << ' ';
    cout << '\n';

    return 0;
}
