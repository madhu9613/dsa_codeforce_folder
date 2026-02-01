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

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}
ll pow(ll a,ll b,ll m)
{
if(b==0)
 return 1;
if(b==1) return a%m;
 ll temp=pow(a,b/2,m);
 if(b%2==0)
 {
 return (temp*temp)%m;
}
else
{
return (a*(temp*temp)%m)%m ;
}
}

const int MOD = 1e9 + 7;
const int INF = INT_MAX;
const ll LINF = 1e18;

const int MAXN = 40005;

void solve() {
    int n,k,l,r;cin>>n>>k>>l>>r;
    vi a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    vi vals = a;
    sort(all(vals));
    vals.erase(unique(all(vals)), vals.end());

    for (int i = 0; i < n; i++)
    {
        a[i] = lower_bound(all(vals), a[i]) - vals.begin();
    }

    auto atmost = [&](int x) -> ll
    {
        if (x < 0)
            return 0;

        vector<int> freq(vals.size(), 0);
        ll ans = 0;
        int left = 0, dist = 0;

        for (int right = 0; right < n; right++)
        {

            if (++freq[a[right]] == 1)
            {
                dist++;
            }

            while (dist > x)
            {
                if (--freq[a[left]] == 0)
                {
                    dist--;
                }
                left++;
            }

            int L1 = max(left, right - r + 1);
            int L2 = right - l + 1;

            if (L1 <= L2)
            {
                ans += (L2 - L1 + 1);
            }
        }
        return ans;
    };

    ll ans=atmost(k)-atmost(k-1);
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--)
        solve();

    return 0;
}