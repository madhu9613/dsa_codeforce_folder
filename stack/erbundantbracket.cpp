#include<iostream>
#include<stack>
using namespace std;
bool isrebundant(string s)
{
    stack<char> ch;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='(' || s[i]=='{' || s[i]=='['|| s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/')
        {
ch.push(s[i]);
        }
        else{
            if(!s.empty())
            {
                if(s[i]==')')
                {
                    while(ch.top()!='(')
                    {
                        
                    }
                }
            }

        }
    }
}
int main()
{
    string input;
    getline(cin,input);

    return 0;
}