#include<iostream>
using namespace std;
void solveeven(int n)
{
    for(int i=1;i<=n-2;i++)
    {
        cout<<3;
    }
    cout<<66<<endl;
}
 void solveodd(int n)
{
    if(n==1 || n==3)
    {
        cout<<-1<<endl;
        return;
    }
    else{
    int a5=36366;
    for(int i=1;i<=n-5;i++)
    {
        cout<<3;
    }
    cout<<a5<<endl;
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        if(n%2==0)
        {
            solveeven(n);
        }
        else{
            solveodd(n);
        }
    }
    return 0;
}