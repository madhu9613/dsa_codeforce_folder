#include<iostream>
using namespace std;
void store(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
}
void print(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<< "  ";
    }
    cout<<endl;
}
void selection_sort(int arr[], int n)
{
    for(int i=0;i<n-1;i++)
    {
      int minindex=i;
      int j;
       for( j=i+1;j<n;j++)
       {
          if(arr[minindex]>arr[j])
          {
            minindex=j;
          }
       }

       swap(arr[minindex],arr[i]);
    }
}
int main()
{
     int n;
     int arr[100];
     cin>>n;
     store(arr,n);
     selection_sort(arr,n);
     print(arr,n);

    return 0;
}