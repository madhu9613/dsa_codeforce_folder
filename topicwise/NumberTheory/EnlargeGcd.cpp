#include <bits/stdc++.h>
using namespace std;

const int MAXA = 15000000;

int spf[MAXA + 1]; 
int freq[MAXA + 1]; 

void precompute_spf() {
    for (int i = 2; i <= MAXA; i++) {
        if (spf[i] == 0) {
            for (int j = i; j <= MAXA; j += i) {
                if (spf[j] == 0) spf[j] = i;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    precompute_spf(); // O(N log log N)

    int n;
    cin >> n;
    vector<int> a(n);
    int g = 0;
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        g = __gcd(g, a[i]);
    }
    
    for (int i = 0; i < n; i++) a[i] /= g;

    for (int x : a) {
        unordered_set<int> used;
        while (x > 1) {
            int p = spf[x];
            if (!used.count(p)) freq[p]++;
            used.insert(p);
            while (x % p == 0) x /= p;
        }
    }

    int mx = 0;
    for (int i = 2; i <= MAXA; i++) {
        mx = max(mx, freq[i]);
    }

    cout << (mx == 0 ? -1 : n - mx) << '\n';
    return 0;
}
