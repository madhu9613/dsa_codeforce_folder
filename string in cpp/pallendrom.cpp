//code to check pallendrom if there is no  case sensitive
#include<iostream>
using namespace std;
int len(char name[])
{int count =0;
for(int i=0;name[i]!='\0';i++)
  {
    count++;

  }
  return count;
}
char tolower(char ch)
{
    if(ch>='a' && ch<='z')
    {
        return ch;
    }
    else{
        //  char temp= ch -'A' +'a';
        //  return temp;
        return ch -'A' +'a';
    }
} 
int palendrom(char name[],int n)
{
    int s=0;
    int e=n-1;
    while(s<e)
    {
      if(tolower(name[s])!=tolower(name[e]))
        {
            return 0;

        }
        else
        {
        s++;
        e--;
        }
    }
    return 1;
}
int main()
{
    char name[20];
cout<<"enter string"<<endl;
cin>>name;
int length=len(name);
int res=palendrom(name,length);
if(res)
{
    cout<<"PALLENDROM"<<endl;
}
else
{
    cout<<"NOt pallendrom"<<endl;
}
    return 0;
}