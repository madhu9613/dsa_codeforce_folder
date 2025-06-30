#include <iostream>
#include <vector>
using namespace std;

void solve()
{
    int t;
    cin >> t; 

    while (t--)
    {

        int n;
        cin >> n;
        vector<int> vec(n);
        for (int i = 0; i < n; i++)
        {
            cin >> vec[i];
        }
        bool possible = false;
        int i = 0;
        while (i < n - 1)
        {
            if (vec[i] > vec[i + 1])

            {
                possible = true;
                break;
            }
            else
            {
                vec[i + 1] -= vec[i];
                vec[i]=0;
            }
            i++;
        }

        if (possible)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }


}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
