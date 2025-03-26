#include<iostream>
#include<vector>
using namespace std;
int findunique(vector<int> &arr)
{
    int uniquenumber=0;
    for(int i:arr)
    {
        uniquenumber ^=i;
    }
    return uniquenumber;
}
int main()
{
    vector<int> arr={1,1,2,3,4,5,2,2,4};
     int res=findunique(arr);
     cout<<"arrey: "<<endl;
     for(int i:arr)
     {
        cout<<i<<" ";
     }
     cout<<endl;
     cout<<"unique number in  the given arrey is :"<<res;
    return 0;
}