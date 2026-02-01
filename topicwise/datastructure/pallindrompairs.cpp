// https : // codeforces.com/problemset/problem/1045/I
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

/***
 *  Need to count pallindrom pairs;(i,j) such that : atleast one permutaion of catenation of s[i]+s[j] form a pallindrom
 * 
 * i donot mind with order i only need to check is they can form a pallindrom; i mean let say some char is even and some char is odd;
 * its only possible that if atleast one combination is pallindrom only iff <=1 odd count;
 *
 */
void solve()
{
int n;cin>>n;
unordered_map<int,ll>cnt;
cnt.reserve(2*n);
for(int i=0;i<n;i++)
{
    string s;cin>>s;
    int mask=0;
    for(char c:s)
    {
        mask^=(1<<(c-'a'));
    }
    cnt[mask]++;
}
ll ans=0;
for(auto &p:cnt)
{
    ll c=p.second;
    ans+=(c*(c-1))/2;
}

ll ans2=0;
for(auto &p:cnt)
{
    int m=p.first;
    ll c=p.second;
    for(int b=0;b<26;b++)
    {
        int m2=m^(1<<b);
        if(cnt.count(m2))
        {
            ans2+=c*cnt[m2];
        }
    }
}

cout<<ans+ans2/2<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while (t--)
        solve();

    return 0;
}