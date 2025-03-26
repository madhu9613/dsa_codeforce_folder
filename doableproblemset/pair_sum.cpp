#include <iostream>
using namespace std;

void store(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void sum(int arr[], int n, int s)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] + arr[j] == s)
            {
                cout << arr[i] << " " << arr[j] << endl;
            }
        }
    }
}

int main()
{
    int num[100];
    int n, s;
    cin >> n;
    cin >> s;
    store(num, n);
    cout << "Entered array is: ";
    print(num, n);

    sum(num, n, s);

    return 0;
}
