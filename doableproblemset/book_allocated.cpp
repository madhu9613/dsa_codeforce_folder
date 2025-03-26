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
        cout<<arr[i];
    }
    cout<<endl;
}
bool ispossible(int arr[],int n, int m,int mid )
{
    int studentcount =1;
    int pagesum=0;
    for(int i=0;i<n ;i++)
    {
        if(pagesum+arr[i]<=mid)
        {
            pagesum+=arr[i];
        }
        else
        {
            studentcount++;
            if(studentcount>m|| arr[i]>mid)
            {
                return false;
            }
            pagesum=arr[i];
        }
    }
    return true;
}
int get_min_page(int arr[],int n, int m)
{
    int start=0;
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum=sum+arr[i];
    }
    int end=sum;
    int mid=(start+end)/2;
    int ans=0;
    while (start<=end)
    {
        if(ispossible(arr,n,m,mid))
        {
            ans=mid;
            end=mid-1;
        }
        else
        {
            start=mid+1;
        }
        mid=(start+end)/2;
    }
    return ans;
}
int main()
{
    int arr[100];
    int n,m;
    cout<<"enter the number of books : "<<endl;
    cin>>n;
    cout<<"enter no of students :"<<endl;
    cin>>m;
     store(arr,n);
     int res=get_min_page(arr,n,m);
     cout<<" requied result is : "<<res;
    return 0;
}