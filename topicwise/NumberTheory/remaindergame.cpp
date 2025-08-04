#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int MAX = 1'000'001;

int spf[MAX];
void compute_sieve() {
    for (int i = 2; i < MAX; i++) {
        if (spf[i] == 0) {
            for (int j = i; j < MAX; j += i) {
                if (spf[j] == 0)
                    spf[j] = i;
            }
        }
    }
}

map<int, int> factorize(int x) {
    map<int, int> factors;
    while (x > 1) {
        int p = spf[x];
        int cnt = 0;
        while (x % p == 0) {
            cnt++;
            x /= p;
        }
        factors[p] = cnt;
    }
    return factors;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> c(n);
    for (int i = 0; i < n; ++i) cin >> c[i];

    auto k_factors = factorize(k);

    map<int, int> max_power;
    for (int i = 0; i < n; ++i) {
        auto f = factorize(c[i]);
        for (auto [p, cnt] : f) {
            max_power[p] = max(max_power[p], cnt);
        }
    }

    for (auto [p, required] : k_factors) {
        if (max_power[p] < required) {
            cout << "No\n";
            return;
        }
    }

    cout << "Yes\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    compute_sieve();
    solve();
    return 0;
}
