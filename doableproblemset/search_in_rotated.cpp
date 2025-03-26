#include<iostream>
using namespace std;
void store(int arr[],int n)
{
    for(int i=0;i<n;i++)

    {
        cin>>arr[i];
    }
}
void print(int arr[], int n) {
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
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
int binary_search(int arr[],int start, int end , int n, int key) {
    int low = start;
    int high = end;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == key) {
            return mid;  // Key found, return the index
        } else if (arr[mid] < key) {
            low = mid + 1;  // Search in the right half
        } else {
            high = mid - 1;  // Search in the left half
        }
    }

    return -1;  // Key not found, return -1
}
int find_position(int arr, int n, int k)
{
    int pivot=getpivot(arr,n);
    if(K>=pivot && k<=arr[n-1])
    {
        binary_search(arr,pivot,(n-1),k);
    }
    else{
        binary_search(arr,0,pivot-1, n,k);
    }
}
int main()
{
    int n;
    int arr[100];
    store(arr,n);
    
}