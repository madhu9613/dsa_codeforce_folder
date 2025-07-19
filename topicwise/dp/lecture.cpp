// Author: Madhujya Rajkhowa
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve()
{
    int n, k;
    cin >> n >> k;
    vi a(n), t(n);

    // Input arrays
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> t[i];

    vi p(n),s(n);
    p[0]=a[0]*t[0];
    for(int i=1;i<n;i++)
    {
        p[i]=a[i]*t[i]+p[i-1];
    }
    int r=0;
    for(int i=n-1;i>=0;i--)
    {
        r+=a[i]*t[i];
        s[i]=r;
    }

    vi prefix(n);
     r=0;
    for(int i=0;i<n;i++)
    {
        r+=a[i];
        prefix[i]=r;

    }
    int ans=0;
    for(int i=0;i+k-1<n;i++)
    {
        int curr=0;
        if(i>0) curr+=p[i-1];
       if(i+k<n) curr+=s[i+k];
       int rangesum=prefix[i+k-1];
       if(i>0) rangesum-=prefix[i-1];
       curr+=rangesum;
       ans=max(ans,curr);
    }
    cout<<ans<<endl;
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
