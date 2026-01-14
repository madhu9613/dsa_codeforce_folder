#include <bits/stdc++.h>

using namespace std;
int n = 0, x;
int main()
{
   
    static long long sum = 0;
    static int i = 0;
    if (n == 0)
        cin >> n;
    i++;
    if (i <= n)
    {
        cin >> x;
        sum += x;
        if (i == n)
            cout << sum;
        return main();
    }
    return 0;
}