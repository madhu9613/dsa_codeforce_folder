#include <stdio.h>
#include<string.h>


int main()
{
int n;
scanf("%d",&n);
char str[n][101];

for(int i=0; i<n;i++)
{
    //store n no of string 
    scanf("%s",str[i]);


}
for(int i=0;i<n;i++)
{
 int len=strlen(str[i]);
 if(len>10)
 {
    printf("%c%d%c\n",str[i][0], len-2,str[i][len-i]);
 }
 else{
    printf("%s\n", str[i]);
 }

}
return 0;
}
    