#include<iostream>
using namespace  std;
int f(int n)
{
    if(n<0)
    {
        return 0;
    }
    if(n==0)

    {
        return 1;
    }
    return f(n-1)+f(n-2);
}
int main()
{
    int n;
    cout<<" initially you are at 0th stair .you can move by one \n or two find no of ways to move to nth?"<<endl;
    cout<<"enter n"<<endl;
    cin>>n;
    int ans=f(n);
    cout<<"no of ways  is : "<<ans<<endl;
    return 0;
}