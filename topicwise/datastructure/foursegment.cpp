#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define max3(a, b, c) max(max(a, b), c)
#define max4(a, b, c, d) max(max(a, b), max(c, d))
#define pii pair<int, int>
#define pll pair<ll, ll>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl '\n'

ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}

ll lcm(ll a, ll b)
{
    return a / gcd(a, b) * b;
}
ll pow(ll a, ll b, ll m)
{
    if (b == 0)
        return 1;
    if (b == 1)
        return a % m;
    ll temp = pow(a, b / 2, m);
    if (b % 2 == 0)
    {
        return (temp * temp) % m;
    }
    else
    {
        return (a * (temp * temp) % m) % m;
    }
}

const int MOD = 1e9 + 7;
const int INF = INT_MAX;
const ll LINF = 1e18;

const int MAXN = 40005;

void solve()
{
    int n;
    cin >> n;
    vll a(n), pref(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        pref[i + 1] = pref[i] + a[i];
    }
    /**
     *
     *
     *  i need to find;
      sum(0,d0)-sum(d0,d1)+sum(d1,d2)-sum(d2,n);

    pref[d0]-pref[d1]+pref[d0]+pref[d2]-pref[d1]-pref[n]+pref[d2]

    2(pref[d0]-pref[d1]+pref[d2])-pref[n]

    need to maximise (pref[d0]-pref[d1]+pref[d2])

    fix middle and precomute for d0 and for d2..
     *
     *
     */

    vll best0(n + 1); 
    vi idx0(n+1);
    best0[0] = pref[0];
    idx0[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        if (pref[i] > best0[i - 1])
        {
            best0[i] = pref[i];
            idx0[i] = i;
        }
        else
        {
            best0[i] = best0[i - 1];
            idx0[i] = idx0[i - 1];
        }
    }

 ll ans = LLONG_MIN;
    int d0 = 0, d1 = 0, d2 = 0;

    for (int mid = 0; mid <= n; mid++)
    {
        for (int right = mid; right <= n; right++)
        {
           ll cur = best0[mid] - pref[mid] + pref[right];
            if (cur > ans)
            {
                ans = cur;
                d0 = idx0[mid];
                d1 = mid;
                d2 = right;
            }
        }
    }

    cout<<d0<<" "<<d1<<" "<<d2<<endl;
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