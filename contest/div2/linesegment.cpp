#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {

        int x,y,k;
        cin>>x>>y>>k;
        int n=min(x,y);
        cout<<0<<" "<<0<<" "<<n<<" "<<n<<endl;
        cout<<n<<" "<<0<<" "<<0<<" "<<n<<endl;
    }
    return 0;
}