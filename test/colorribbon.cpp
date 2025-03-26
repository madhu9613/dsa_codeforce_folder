#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, k;
        cin >> n >> m >> k;
        if(m==k==n)
        {
            cout<<"NO"<<endl;
        }
       else  if (m == 1)
        {
            cout << "NO" << endl;
        }
        else if (k >= n)
        {
            cout << "YES\n"
                 << endl;
        }
        else if (m == k)
        {
            cout << "NO\n"
                 << endl;
        }
        else if (m > k)
        {
            cout << "YES\n"
                 << endl;
        }
    }
    return 0;
}