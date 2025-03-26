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
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void merg(int arr1[],int n1,int arr2[],int n2, int arr3[])

{
    int i=0;int j=0;

    int k=0;
  while(i<n1 && j<n2)
  {
    if(arr1[i]<arr2[j])
    {
        arr3[k++]=arr1[i++];
       
    }
    else{
        arr3[k++]=arr2[j++];
        
    }
  }
    while(i<n1)
    {
        arr3[k++]=arr1[i++];
       
    }
    while(j<n2)
    {
        arr3[k++]=arr2[j++];
        
    }
  }

int main()
{int arr1[100];
int arr2[100];
int arr3[200];
    int n,m;
cout<<"ENTER N AND M : "<<endl;
cin>>n>>m;
cout<<"store 1"<<endl;
store(arr1,n);
cout<<"store 2"<<endl;
store(arr2,m);
merg(arr1,n,arr2,m,arr3);
int c=n+m;
print(arr3,c);
    return 0;
}