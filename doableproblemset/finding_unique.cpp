#include<iostream>
using namespace std;

int find_unique_element(int arr[],int n)
{
    int ans=0;
    for(int i=0;i<n;i++)
    {
        ans=ans^arr[i];
    }
    return ans;
}
void store(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
}

int main()
{   int num[100];
int n;
    cout<<"enter size: "<<endl;
    cin>>n;
    store(num,n);
int unique=  find_unique_element(num,n);
    cout<<"unique number is : "<<unique;

    return 0;
}