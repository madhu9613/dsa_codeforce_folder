#include<iostream>
using namespace std;
int main()
{
int t;
cin>>t;
while(t--)
{
    long long n,m,r,c;
    cin>>n>>m>>r>>c;
    long long ans=(m-c)+(n-r)*(2*m-1);
    cout<<ans<<endl;
}

    return 0;
}