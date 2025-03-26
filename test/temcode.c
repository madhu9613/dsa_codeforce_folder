#include <stdio.h>
int zeroindex(char ch)
{
    if (ch >= 'A' && ch <= 'Z')
    {
        return ch - 'A';
    }
    else if(ch>='a'&& ch<='z')
    {
        return ch - 'a';
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    char arr[101];
    int level[26]={0};
    scanf("%s", arr);
    if (n < 26)
    {
        printf("NO\n");
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
           int a=zeroindex(arr[i]);
           arr[a]=1;
        }
       for(int i=0;i<=26;i++)
       {
        printf("%2d\n",arr[i]);
       }
    }
    return 0;
}