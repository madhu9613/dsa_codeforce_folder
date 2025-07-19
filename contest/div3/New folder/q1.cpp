#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int tt;cin>>tt;
    while (tt--)
    {
         string x;
        cin >> x;
        set<char> digits(x.begin(), x.end());

        for (char d = '0'; d <= '9'; d++) {
            if (digits.count(d)) {
                cout << d << '\n';
                break;
            }
        }
    }
    
    return 0;
}