#include <iostream>
using namespace std;

void arreymerge(int *arr, int s, int e)
{
    int mid = s + (e - s) / 2;
    // creat two arrey
    int l1 = mid - s + 1;
    int l2 = e - mid;
    int *first = new int[l1];
    int *second = new int[l2];
    int k = s;
    //copy element
        for (int i = 0; i < l1; i++)
    {
        first[i] = arr[k++];
    }
    //copy element
    k = mid + 1;
    for (int i = 0; i < l2; i++)
    {
        second[i] = arr[k++];
    }
    //merging two sortes arrey
    int i=0; //for arrey 1
    int j=0; //for arrey 2
    int mainarreyindex=s;
    while(i<l1 && j<l2)
    {
        if(first[i]<second[j])
        {
            arr[mainarreyindex++]=first[i++];
        }
        else{
            arr[mainarreyindex++]=second[j++];
        }
    }
    while(i<l1)
    {
        arr[mainarreyindex++]=first[i++];
    }
    while(j<l2)
    {
        arr[mainarreyindex++]=second[j++];
    }
    delete[] first;
    delete[] second;
}
void mergesort(int arr[], int s, int e)
{
    if (s >= e)

    {
        return;
    }
    int mid = s + (e - s) / 2;
    mergesort(arr, s, mid);
    mergesort(arr, mid + 1, e);
    arreymerge(arr, s, e);
}
int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    mergesort(arr, 0, n - 1);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    delete[] arr;
        return 0;
}