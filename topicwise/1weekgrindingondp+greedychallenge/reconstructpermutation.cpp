#include <bits/stdc++.h>
using namespace std;
int a[1009], n, k;
int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        int j;
        for (j = 1; j <= n; j++)
            if (!a[j])
                break;
        cout << j << ' ';
        for (int q = 1; q <= j - k; q++)
            a[q]--;
        a[j]--;
    }
}