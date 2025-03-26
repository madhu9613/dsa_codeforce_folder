/*

process;
create a maxheap for first kth element then ,then procces the next kth element..
if element <heap.top()
then pop element from heap and insert the element

*/
#include<bits/stdc++.h>
using namespace std;
int kthmaxima(int k,int arr[],int n)
{
 priority_queue<int,vector<int> ,greater<int> > pq;
 
 for(int i=0;i<k;i++)
 {
    pq.push(arr[i]);
 }
 for(int i=k;i<n;i++)
 {
    if(arr[i]>pq.top())
    {
        pq.pop();
        pq.push(arr[i]);
    }
 }
 return pq.top();

}
int kthminima(int k,int arr[],int n)
{
 priority_queue<int> pq;
 for(int i=0;i<k;i++)
 {
    pq.push(arr[i]);
 }
 for(int i=k;i<n;i++)
 {
   if(arr[i]<pq.top())
   {
    pq.pop();
    pq.push(arr[i]);
   }
 }
return pq.top();
}
int main()
{
    int n;
    cin>>n;
    int* arr=new int[n];

for(int i=0;i<n;i++)
{
   cin>>arr[i];
}
int k;
cin>>k;

int ans=kthminima(k,arr,n);
cout<<"kth minima is :"<<ans<<endl;
int kmax=kthmaxima(k,arr,n);

cout<<"kth maxima is :"<<kmax<<endl;
    return 0;

}