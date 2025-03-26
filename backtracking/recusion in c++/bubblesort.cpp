#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n)
{
    if (n == 0 || n == 1)
    {
        return;
    }

    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            swap(arr[i], arr[i + 1]);
        }
    }

    bubbleSort(arr, n - 1);
}

int main()
{
    int n;

    // Ask the user for the size of the array
    cout << "Enter the number of elements: ";
    cin >> n;

    // Allocate memory for the array
    int *arr = new int[n];

    cout << "Enter the elements:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Call the bubble sort function
    bubbleSort(arr, n);

    // Print the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Deallocate the memory
    delete[] arr;

    return 0;
}
