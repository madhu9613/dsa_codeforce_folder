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

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

const int MOD = 1e9 + 7;
const int INF = INT_MAX;

// Count divisors using sqrt(x)
int count(int x) {
    int c = 0;
    for (int k = 1; k * k <= x; k++) {
        if (x % k) continue;
        c++;
        if (k != x / k) c++;
    }
    return c;
}

// Check if a number is prime
bool prime(int n) {
    if (n < 2) return false;
    for (int x = 2; x * x <= n; x++) {
        if (n % x == 0) return false;
    }
    return true;
}

// Prime factorization
map<int, int> factors(int n) {
    map<int, int> f;
    for (int x = 2; x * x <= n; x++) {
        while (n % x == 0) {
            f[x]++;
            n /= x;
        }
    }
    if (n > 1) f[n]++; 
    return f;
}

// DFS-like divisor generator
vector<int> divisors;
void generatedivisor(vector<pair<int, int>>& pf, int idx, int cur) {
    if (idx == pf.size()) {
        divisors.pb(cur);
        return;
    }
    int p = pf[idx].first;
    int cnt = pf[idx].second;
    for (int i = 0; i <= cnt; ++i) {
        generatedivisor(pf, idx + 1, cur);
        cur *= p;
    }
}
ll extended_gcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll g = extended_gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}
void solve() {
    int x;
    cin >> x;
    cout << "Total number of divisors: " << count(x) << endl;

    map<int, int> pf_map = factors(x);
    vector<pair<int, int>> pf(pf_map.begin(), pf_map.end());

    divisors.clear(); // Clear global vector before use
    generatedivisor(pf, 0, 1);
    sort(all(divisors));

    cout << "Divisors of " << x << ": ";
    for (int d : divisors) cout << d << " ";
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
