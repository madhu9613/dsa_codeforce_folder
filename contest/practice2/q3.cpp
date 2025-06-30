#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin>>n;
        string s;
        cin >> s;
        vector<int> isfirst(26, 0);
        int ans = 0;
        for (int i = 0; i < n; i++)
        {

            if (isfirst[s[i] - 'a'] == 0)
            {
                ans += (n - i);
                isfirst[s[i] - 'a'] = 1;
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}