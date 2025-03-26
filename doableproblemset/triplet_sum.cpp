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

void trip_sum(int arr[], int n, int s)
{
    bool found = false;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (arr[i] + arr[j] + arr[k] == s)
                {
                    // Ensure triplet is printed in ascending order
                    cout << arr[i] << " " << arr[j] << " " << arr[k] << endl;
                    found = true;
                }
            }
        }
    }

    if (!found)
    {
        cout << "No such triplet exists for the given input" << endl;
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

    trip_sum(num, n, s);

    return 0;
}
