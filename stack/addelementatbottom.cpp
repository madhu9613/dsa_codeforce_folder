#include <iostream>
#include <stack>
#include<sstream>
using namespace std;

void addbottom(stack<int> &s, int x)
{
    if (s.empty())
    {
        s.push(x);
        return;
    }
    int num = s.top();
    s.pop();

    addbottom(s, x);
    s.push(num);

}
void print(stack<int> s)
{
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
}
int main()
{
    string input;
    getline(cin, input);
    stack<int> s;
   stringstream ss(input);
   int data;

   while(ss>>data)
   {
    s.push(data);
   }
   cout<<"element in stake is :\n";
   print(s);
    int avg;
    int sum = 0;
    int n=s.size();
    stack<int> temp=s;
    while (!temp.empty())
    {
        sum += temp.top();
        temp.pop();
    }
    avg=sum/n;
    addbottom(s, avg);
    cout<<"after adding average at bottom\n";
    print(s);
    cout<<endl;
    return 0;
}