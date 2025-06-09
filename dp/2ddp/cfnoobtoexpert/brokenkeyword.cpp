#include<bits/stdc++.h>
#define int long long
using namespace std;
int32_t main()
{
    
int n,k;
cin>>n>>k;
vector<int>alpha(26,0);
string s;
cin>>s;
for(int i=0;i<k;i++)
{
    char c;
    cin>>c;
    int idx=c-'a';
    alpha[idx]=1;
}

int ans=0;
int c=0;
for(int i=0;i<n;i++)
{
    int idx=s[i]-'a';
    if(alpha[idx]==0)
    {
        ans+=c*(c+1)/2;
        c=0; //reset c;
    }
    else{
        c++;
    }
}

ans+=c*(c+1)/2;
cout<<ans<<endl;



    return 0;
}
