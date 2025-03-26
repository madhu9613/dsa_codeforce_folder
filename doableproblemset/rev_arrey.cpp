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
void rev(int arr[],int n,int m)
{
    int s=m+1;
    int e=n-1;
    while(s<e)
    {
        swap(arr[s],arr[e]);
        s++;
        e--;
    }
}
int main()
{

 int n,m;
 printf("ENter the size of an arrey :\n");
 scanf("%d",&n);
   int arr[100];
    store(arr,n);
    printf("before reverse the array is :: \n");
    print(arr,n);
    printf("enter index after which you want to rev arrey(0  to n )\n");
    scanf("%d",&m);

    rev(arr,n,m);
    printf("After reverse the array ::\n");
    print(arr,n);
        return 0;
}