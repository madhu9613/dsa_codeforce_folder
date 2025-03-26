 #include<iostream>
using namespace std;


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
char toupper(char ch)
{
    if(ch>='A' && ch<='Z')
    {
        return ch;
    }
    else{
        char temp=ch-'a'+'A';
        return temp;
    }
}
int main()
{
   
cout<<"character to lowwer case is "<<tolower('A')<<endl;
cout<<"character to upper case is "<<toupper('p')<<endl;
}
    