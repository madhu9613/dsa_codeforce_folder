// arr[]={9,10,11,1,2,3,4}

#include <iostream>
using namespace std;
int getpivot(int *arr, int n)
{
    int start = 0;
    int end = n - 1;
    int mid = (start + end) / 2;
    while (start < end)
    {
        if (*(arr + mid) >= *arr)
        {
            start = mid + 1;
        }
        else
        {
            end = mid;
        }
        mid = (start + end) / 2;
    }

    return end;
}
void store(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> *(arr + i);
    }
    cout << endl;
}
void print(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << *(arr + i) << " " << endl;
    }
}
int main()

{

    int n;
    int arr[100];
    cin >> n;
    store(arr, n);
    print(arr, n);
    int res = getpivot(arr, n);
    cout << "pivot is fout at index   " << res << " and position  " << res + 1 << endl;
    cout << "largest integer is : " << arr[res - 1];
    return 0;

    

}