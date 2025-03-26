#include<iostream>
using namespace std;
void store(int arr[][3],int n, int m)
{
for(int i=0;i<n;i++)
{
    for(int j=0;j<m;j++)
    {
        cin>>arr[i][j];
    }
}
}

void  print(int arr[][3],int n, int m)
{
for(int i=0;i<n;i++)
{
    for(int j=0;j<m;j++)
    {
        cout<<arr[i][j]<<" ";
    }
    cout<<endl;
}
}
bool ispresent(int arr[][3],int n, int m,int target)
{
    for(int i=0;i<n;i++)
    {

        for(int j=0;j<m;j++)
        {
            if(arr[i][j]==target)
            {
                return 1;
            }
            
        }
    }
    return 0;
}
int main()
{
    int arr[3][3];
    int target;
    store(arr,3,3);
    print(arr,3,3);
    cout<<"enter the element you want to search : "<<endl;
    cin>>target;
    if(ispresent(arr,3,3,target))
    {
        cout<<"element found";
    }
    else
    {
        cout<<"element not found ";
    }
    return 0;
}