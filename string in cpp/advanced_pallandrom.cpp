#include<iostream>
#include<string.h>
using namespace std;
char tolower(char c)
{
    if(c>='a'&& c<='z')
    {
        return c;
    }
    else{
        return c-'A' +'a';
    }
}
bool isvalid(char c)
{
    return (c>='A' && c<='Z') || (c>='a'&&c<='z') ||(c>='0'&& c<='9');
}
bool pallendrom(const string &str, int n)
{
    int s=0;
    int e=n-1;
    while(s<e)
    {
        while(s<e && !isvalid(str[s]))
        {
           s++;
        }
        while(s<e && !isvalid(str[e]))
        {
            e--;
        }
        if(tolower(str[s])!=tolower(str[e]))
        {
           return false;
        }
        else{
            s++;
            e--;
        }

    }
    return true;
}
int main()
{

    string input;
    cout<<"enter a string"<<endl;
    getline(cin,input);
   if( pallendrom(input,input.length()))
   {
    cout<<"pallendrom"<<endl;

   }
   else{
    cout<<"not pallendrom"<<endl;
   }
    return 0;
}