#include<bits/stdc++.h>
#define int long long

using namespace std;

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;cin>>tt;
    while(tt--)
    {
        int k,a,b,x,y;
        cin>>k>>a>>b>>x>>y;
        int ans=0;
        if(k<a && k<b)
        {
            ans=0;
        }
        else {
      
            if(k>=a && k<b)
            {
                ans+=(k-a)/x+1;
            }
            else if(k>=b && k<a)
            {
                ans+=(k-b)/y+1;
            }
            else{
           
                int mini=min(x,y);
                if(mini==x)
                {
                    //a will be used;
                    // ans+=(k-a)/x+1;
                    int n=(k-a)/x+1;
                    ans+=n;
                    k=k-n*x;
                    if(k>=b)
                    {
                        ans+=(k-b)/y+1;
                    }
                }
                else{
                    int n=(k-b)/y+1;
                    ans+=n;
                    k=k-n*y;
                    if(k>=a)
                    {
                        ans+=(k-a)/x+1;
                    }
                }

            }

        }

        cout<<ans<<endl;
        
        

    }
    return 0;
}