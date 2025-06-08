/*

heapify algorithm

*/
#include<iostream>

#include<sstream>
using namespace std;
 
    
//maximum heapify following 1 based index t(c)->log(n)
void heapify(int arr[], int size,int i)
{
    int largest=i;
    int leftchild=2*i;
    int rightchild=2*i+1;
     if(leftchild<=size && arr[largest]<=arr[leftchild]  )
     {
        largest=leftchild;
     }
     if(rightchild<=size && arr[largest]<=arr[rightchild])
     {
        largest=rightchild;
     }
     if(largest!=i)
     {
        swap(arr[largest],arr[i]);
        heapify(arr,size,largest);

     }
}

void heapSort(int arr[], int size)
{
int n=size;
    while(n>1)
    {
     swap(arr[1],arr[n]);
     n--;
     heapify(arr,n,1);
    }
}

void print(int arr[],int size)
{
    for(int i=1;i<=size;i++)
    {
        cout<<arr[i]<<" ";
    }cout<<endl;
}
int main()
{
    int arr[]={-1,54,55,53,52,50};
    int size=sizeof(arr)/sizeof(arr[0])-1;
    // for building heap t(c)->O(n):
    for(int i= size/2;i>0;i--)
    {
        heapify(arr,size,i);
    }
    //after heapify printing the arrey:
    print(arr,size);
//heapsort

heapSort(arr,size);
cout<<"after sorting heapsort"<<endl;
print(arr,size);
    return 0;

}