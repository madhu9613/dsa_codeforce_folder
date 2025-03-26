#include<iostream>
#include<stack>
using namespace std;
int main()
{
string input;
getline(cin,input);
stack <char> c ;
for(int i=0;i<input.size();i++)
{
  char ch=input[i];
  c.push(ch);
}

cout<<"string in reverse order is \n";
int i=0;
while(!c.empty())
{
input[i]=c.top();

c.pop();
i++;
}
cout<<input;
cout<<endl;

    return 0;
}