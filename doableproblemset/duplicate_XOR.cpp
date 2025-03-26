#include<iostream>
using namespace std;

int find_duplicate(int arr[],int n)
{  
    int ans =0;
    for(int i=0;i<n;i++)
    {
        ans^=arr[i];
    }
    for(int i=1;i<n;i++)

    {
        ans^=i;
    }
    return ans ;
}
void store(int arr[],int n)
{
    for(int i=0;i<n;i++)

    {
        cin>>arr[i];
    }
}

int main()

{ 
    int num[100];
    int n;
    cin>>n;
    store(num,n);
    int dup=find_duplicate(num,n);
    cout<<"the duplicate number is : "<<dup;

    return 0;
}