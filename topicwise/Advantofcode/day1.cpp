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

ll gcd(ll a, ll b)
{
 return b == 0 ? a : gcd(b, a % b);
}
const int MOD = 1e9 + 7;
const int INF = INT_MAX;

void solve() {
vll left;
vll right;
ll a,b;
while (cin>>a>>b)
{
    left.pb(a);
    right.pb(b);
}
sort(all(left));
sort(all(right));
int n=left.size();

ll ans=0;
unordered_map<ll,ll>freq_of_right;
for(int i=0;i<n;i++)
{
    freq_of_right[right[i]]++;
}

for(int i=0;i<n;i++)
{
    ans+=left[i]*freq_of_right[left[i]];
}
cout<<ans<<endl;



}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    while (t--) solve();
    return 0;
}