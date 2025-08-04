#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define max3(a, b, c) max(max(a, b), c)
#define max4(a, b, c, d) max(max(a, b), max(c, d))
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()
#define endl '\n'

ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}
const int MOD = 1e9 + 7;
const int INF = INT_MAX;
map<int, int> factors(int n)
{
    map<int, int> f;
    for (int x = 2; x * x <= n; x++)
    {
        while (n % x == 0)
        {
            f[x]++;
            n /= x;
        }
    }
    if (n > 1)
        f[n]++;
    return f;
}
int nextPowerOfTwo(int n)
{
    if (n <= 1)
        return 2;
    n--;
    n |= n >> 1;
    n |= n >> 2;
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;
    return n + 1;
}

void solve()
{

    int n;
    cin >> n;
    map<int, int> ans = factors(n);
    int new_n = 1;

    int largest = 0;

    bool same = true;
    int first_b = -1;

    for (auto &[a, b] : ans)
    {
        new_n *= a;

        if (first_b == -1)
            first_b = b;
        else if (b != first_b)
            same = false;

        if ((b & (b - 1)) != 0)
            same = false;

        int k = nextPowerOfTwo(b);
        largest = max(largest, k);
    }

    cout << new_n << " ";
    if(new_n==n)
    {
        cout<<0<<endl;
        return;
    }
    int ops = 0;
    int temp = largest;
    while (temp > 1)
    {
        temp /= 2;
        ops++;
    }
    if(same)
    {
        cout<<ops<<endl;
    }else{
        cout<<ops+1;
    }

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    while (t--)
        solve();
    return 0;
}