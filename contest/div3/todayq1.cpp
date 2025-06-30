#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt;cin>>tt;
    while(tt--)
    {
        int n,s;
         cin>>n>>s;
        vector<int>a(n);
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        // int ans=a[n-1]-s +(a[n-1]-a[0])   ;
        //  cout<<abs(ans)<<endl;
        if(s<=a[0])
        {
            cout<<a[n-1]-s<<endl;
        }
        else if(s>=a[n-1]){
            cout<<s-a[0]<<endl;

        }else{
            int ans=min(a[n-1]-s +(a[n-1]-a[0]),s-a[0]+a[n-1]-a[0])   ;
         cout<<abs(ans)<<endl;
        }
    }
    return 0;
}