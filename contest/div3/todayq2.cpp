#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt;cin>>tt;
    while(tt--)
    {
        int n;cin>>n;
        string s;cin>>s;
        vector<int>a(26,0);
        bool pos=false;
        for(int i=0;i<n-1;i++)
        {
            if(a[s[i]-'a']!=0)
            {
                pos=true;
                break;
            }
            a[s[i]-'a']++;

        }
        if(pos==false)
        {
            vector<int>b(26,0);
            for(int i=n-1;i>0;i--)
        {
            if(b[s[i]-'a']!=0)
            {
                pos=true;
                break;
            }
            b[s[i]-'a']++;

        }

        }
        if(pos)
        {
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}