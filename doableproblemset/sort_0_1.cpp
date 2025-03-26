#include<iostream>
using namespace std;
void store(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void sortone(int arr[],int n)
{
    int left=0;
    int right =n-1;
    while(left<=right)
    {
        while (arr[left]==0 && left<right)

        {
            left ++;
        }
        
       while (arr[right]==1 && left<right)
        {
            right--;
        }
        if(left<right)
        {
        swap(arr[left],arr[right]);
        left++;
        right--;
        }
    }
}
int main()
{
    int n=8;
int num[100];
store(num,n);
sortone(num,n);
print(num,n);


}