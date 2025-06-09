#include <bits/stdc++.h>
#define int long long
using namespace std;
int solve(int x)
{
    return pow(2, x);
}
int32_t main()
{
  
        int n;
        cin >> n;
        int ans;
        if (n%2==1)
        {
            ans = 0;
        }
        else
        {
            ans = solve(n / 2);
        }
        cout << ans << endl;
    
}