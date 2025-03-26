#include <stdio.h>
#include <stdlib.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void bubblesort(int *arr, int n)
{
    if (n <= 1)
    {
        return;
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            swap(&arr[i], &arr[i + 1]);
        }
    }
    bubblesort(arr, n - 1);
}
// from where to where for entire arrey l=0;r=n-1;
void merge(int arr[], int l, int mid, int r)

{
    int n1 = mid - l + 1;
    int n2 = r - mid;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[l + i];
    }
    for (int i = 0; i < n2; i++)
    {
        R[i] = arr[mid + i + 1];
    }
    int i=0,j=0,k=l;
   while(i<n1 && j<n2)
   {
    if(L[i]<=R[j])
    {
        arr[k++]=L[i++];
    }
    else{
        arr[k++]=R[j++];
    }
   }
   while(i<n1)
   {
    arr[k++]=L[i++];
   }
   while(j<n2)
   {
    arr[k++]=R[j++];
   }
}
void mergesort(int arr[], int l, int r)
{
    if (l < r)
    {
        int mid = l + (r - l) / 2;
        mergesort(arr, l, mid);
        mergesort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
}

void display(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main()
{
    int n;
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)

    {
        scanf("%d", &arr[i]);
    }
    display(arr, n);
    // bubblesort(arr, n);
    // display(arr, n);
    mergesort(arr,1,n-1);
    display(arr,n);
}
