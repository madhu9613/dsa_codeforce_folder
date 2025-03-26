#include<stdio.h>
void store(int arr[], int n)
{
 for(int i=0;i<n;i++)
 {
    scanf("%d",&arr[i]);
 }
}
void print(int arr[], int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d  ",arr[i]);
    }
    printf("\n");
}
void swap(int *a, int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

void selection_sort(int arr[], int n)
{
    for(int i=0;i<n;i++)
    {
        int maxindex=i;

        for(int j=i+1;j<n;j++)
        {
            if(arr[maxindex]<arr[j])
            {
                maxindex=j;
            }
        }
       swap(&arr[maxindex],&arr[i]);
    }
}
int main()
{
    int n;
    int arr[100];
    scanf("%d",&n);
    store(arr,n);
    selection_sort(arr, n);
    print(arr,n);
    return 0;
}