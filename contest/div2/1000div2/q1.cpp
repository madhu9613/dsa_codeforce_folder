/*

QUEATION NO 1
*/
#include<bits/stdc++.h>
using namespace std;

void solve() {
    int t;
    cin >> t;
    while (t--) {
        string s;
      cin>>s;
        int n=s.size();
        int a=0;
        for (int i=0;i<n;i++)
        {
            if(s[i]=='1')
            { a++;
                s[i]=0;
            }
            else s[i]=1;

        }
        int b=n-a;
        int ans;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='0')
            {
                if(b==0)
                {
                    ans=n-i;
                    break;
                }
                b--;
            }
            else
            {
                if(a==0)
                { ans=n-i;
                    break;
                    
                }
                a--;
            }
            
        }
        cout<<ans<<endl;
        
    }
}

int main() {
   ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}