#include <stdio.h>

int main(){
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,k;
        scanf("%d%d",&n,&k);
        if(k==0)
        {
            printf("%d\n",k);

        }
        else{
        k-=n;
        int cur=n-1;
        int ans=1;
        

         
        while(k>0 && cur>=1)
        {
            k-=cur;
            ans++;
            if(k>0)
            {
                k-=cur;
                ans++;
            }
          cur--;
        }
        printf("%d\n",ans);
        }
    }
    return 0;
}