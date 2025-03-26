#include<iostream>
using namespace std;
int find_duplicate(int arr[], int n)
{
    int sum1=0;
    int sum2=0;
    int ans;
    for(int i=0;i<n;i++)
    {
        sum1+=arr[i];
        sum2+=i;
        

    }
    ans=sum1-sum2;
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
{   
  
 int num[100];
  int n;
  cin>>n;
    store(num,n);
    int dup=find_duplicate(num,n);
    cout<<"duplicate number is :";
    cout<<dup;
    return 0;
}