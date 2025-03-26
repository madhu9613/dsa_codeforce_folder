#include<iostream>
using namespace std;
void merge(int *arr,int s,int e)
{
    int mid=s+(e-s)/2;
    int len1=mid-s+1;
    int len2=e-mid;
    int *first=new int[len1];
    int *second=new int[len2];
    ///copy the value
    int k=s;
    for(int i=0;i<len1;i++)
    {
        first[i]=arr[k++];
    }
    int k=mid+1;
    for(int i=0;i<len2;i++)
    {
        second[i]=arr[k++];
    }

}
void mergesort(int* arr,int s ,int e)
{
    if(s>e)
    {
        return;
    }
  int  mid=s+(e-s)/2;
  //sort left part
  mergesort(arr,s,mid);
  //sort right part
  mergesort(arr,mid+1,e);

merge(arr,s,e);
}
int main()
{
int n;
int *arr=new int[n];
for(int i=0;i<n;i++)

{
    cin>>arr[i];
}

    return 0;
}