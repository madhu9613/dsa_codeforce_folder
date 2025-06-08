#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
   while (t--)
   {
    int n;
    cin>>n;
    int l=0;
    int r=n-1;
    
    vector<int> ans(n);
    for(int i=1;i<=n;i++)
    {
        if(i%2==0)
        {
            ans[r]=i;
            r--;
        }
        else{
            ans[l]=i;
            l++;
        }


    }
    //print the array
    for(auto &x:ans)
    {
        cout<<x<<" ";

    }
    cout<<endl;
   }
   
    return 0;
}