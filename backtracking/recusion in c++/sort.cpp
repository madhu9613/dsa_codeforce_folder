#include <iostream>
using namespace std;
bool issortedinassending(int *arr, int n)
{
    if (n == 1 || n == 0)
    {
        return true;
    }
    if (arr[0] > arr[1])
    {
        return false;
    }
    return issortedinassending(arr + 1, n - 1);
}

bool issortedindesending(int *arr, int n)
{
    if (n == 1 || n == 0)
    {
        return true;
    }
    if (arr[0] < arr[1])
    {
        return false;
    }

    return issortedindesending(arr + 1, n - 1);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int *arr = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        bool ans1 = issortedinassending(arr, n);
        if (ans1)
        {
            cout << "sorted in assending order\n"
                 << endl;
        }
        else
        {
            int ans2=issortedindesending(arr,n);
            if(ans2)
            {
                cout<<"sorted in dessending order"<<endl;
            }
            else
            {
                cout<<"not sorted \n"<<endl;
            }
        }
    }
    return 0;
}
// if size ==1 or 0 already sorted