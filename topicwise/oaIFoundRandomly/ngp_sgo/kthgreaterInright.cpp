#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
#define vi vector<int>
#define vll vector<ll>
#define vpi vector<pii>
#define vpll vector<pll>

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

const ll INF = 1e18;
const int MOD = 1000000007;

// Fast exponentiation (a^b % mod)
ll modpow(ll a, ll b, ll mod = MOD) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

ll modinv(ll a, ll mod = MOD) {
    return modpow(a, mod - 2, mod);
}

// GCD
ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

// LCM
ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

void solve() {
    int n,k;cin>>n>>k;
    vi nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }

    vector<int> ans(n, -1);

    vector<vector<int>> st(k);

    for (int i = 0; i < n; i++)
    {

        while (!st[k - 1].empty() &&
               nums[st[k - 1].back()] < nums[i])
        {

            ans[st[k - 1].back()] = nums[i];
            st[k - 1].pop_back();
        }

        for (int level = k - 2; level >= 0; level--)
        {

            vector<int> temp;

            while (!st[level].empty() &&
                   nums[st[level].back()] < nums[i])
            {

                temp.push_back(st[level].back());
                st[level].pop_back();
            }

            for (int j = (int)temp.size() - 1; j >= 0; j--)
            {
                st[level + 1].push_back(temp[j]);
            }
        }

        st[0].push_back(i);
    }

    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}