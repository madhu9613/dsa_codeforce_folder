#include<iostream>
#include<stack>
using namespace std;


bool ispara(string input)
{
    stack <char> s;
    for(int i=0;i<input.size();i++)
    {
        if(input[i]=='(' || input[i]=='{'|| input[i]=='[')
        {
            s.push(input[i]);
        }
        else{
            if(!s.empty())
            {
                char top=s.top();
                if(input[i]==')' && top=='(' || input[i]=='}' || top=='{' || input[i]==']' || top==']')
                {
                    s.pop();
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
        }
        
    }
    if(s.empty())
        {
            return true;
        }
        else{
            return false;
        }
}
int main()
{
    string input;
    getline(cin,input);
    if(ispara(input))
    {
        cout<<"BALANCED"<<endl;
    }
    else{
        cout<<"NOT"<<endl;
    }



    return 0;
}