#include<iostream>

using namespace std ;


void alt_swap(int arr[],int size)
{
    for(int i=0;i<size;i+=2)
    {
        if(i+1<size)

        {
            swap(arr[i],arr[i+1]);
        }
    }
}
void printarrey(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }cout<<endl;
}
int main()
{   

    int even [8]={3,5,7,8,9,7,5,9};
    int odd[5]={1,2,4,65,7};
    alt_swap(even,8);
    printarrey(even,8);

    alt_swap(odd,5);
    printarrey(odd,5);
    return 0;
}