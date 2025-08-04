// Author: Madhujya Rajkhowa
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define all(x) (x).begin(), (x).end()
#define endl '\n'

const int MOD = 1e9 + 7;
const int INF = INT_MAX;

// see if we perform bitwise and operation it will not increase the value either it decrease or stay same
void solve()
{

    //see i can choose any intervel [l,r] an perfom al+i=(al+i & ar-i) if we choose repetadely we can see that i can make a number equal to (and of all the number
    
    int n;
    cin >> n;
    vll a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ll x = a[0];
    for (int i = 0; i < n; i++)
    {
        x &= a[i];
    }
    cout << x << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}