#include <iostream>
#include <vector>
#define ll long long
using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 1e9;

vector<ll> fact(MAXN + 1), inv(MAXN + 1);

// Fast exponentiation: a^b % mod
ll power(ll base, ll exp, ll mod) {
    ll result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2) result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

// Precompute factorials and inverses up to MAXN
void preprocess() {
    fact[0] = 1;
    for (int i = 1; i <= MAXN; i++)
        fact[i] = (fact[i - 1] * i) % MOD;

    inv[MAXN] = power(fact[MAXN], MOD - 2, MOD);
    for (int i = MAXN - 1; i >= 0; i--)
        inv[i] = (inv[i + 1] * (i + 1)) % MOD;
}

// Compute C(n, r) % MOD for small n, r ≤ MAXN
ll binomial_coefficient(int n, int r) {
    if (r > n || r < 0) return 0;
    return fact[n] * inv[r] % MOD * inv[n - r] % MOD;
}

// Lucas's Theorem for large nCr % MOD
ll lucas(ll n, ll r, ll p) {
    if (r == 0) return 1;
    return lucas(n / p, r / p, p) * binomial_coefficient(n % p, r % p) % p;
}

int main() {
    preprocess();

    int t;
    cin >> t;
    while (t--) {
        ll a, b, k;
        cin >> a >> b >> k;

        ll kn = k * (a - 1) % MOD;
        ll n_md = (kn + 1) % MOD;

        // Use Lucas's theorem for large C(n_md, a)
        ll cn = lucas(kn + 1, a, MOD);  // NOTE: use original (not %MOD) for Lucas
        ll bm = (b - 1) * k % MOD;
        ll m_md = (bm * cn + 1) % MOD;

        cout << n_md << " " << m_md << "\n";
    }

    return 0;
}
