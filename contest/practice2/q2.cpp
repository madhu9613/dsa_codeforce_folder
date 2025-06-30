#include <iostream>
using namespace std;

void solve()
{
    int t;
    cin >> t;

    while (t--)
    {
        int K;
        cin >> K;

        if (K % 2 == 0)
        { 

            cout << K / 2 << " " << K / 2 << endl;
        }
       else if (K % 3 == 0)
        {
            cout << K / 3 << " " << 2 * (K / 3) << endl;
        }
        else{
            cout<<1<<" "<<K-1<<endl;
        }
    }
}

int main()
{
    solve();
    return 0;
}
