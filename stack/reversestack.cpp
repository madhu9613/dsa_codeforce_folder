#include <iostream>
#include <stack>
#include <sstream>
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
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout<<endl;
}
void reversestack(stack<int> &s)
{
    // basecae
    if (s.empty())
    {
        return;
    }
    int num = s.top();
    s.pop();
    // rec call;
    reversestack(s);
    addbottom(s, num);
}
void sortedinsert(stack<int> &s,int element)
{
    if(s.empty() || s.top()<=element)
    {
        s.push(element);
        return;
    }
    int num=s.top();
    s.pop();

    sortedinsert(s,element);
    s.push(num);
}
void sortstack(stack<int> &s)
{
    if(s.empty())
    {
        return;
    }
    int num=s.top();
    s.pop();
    sortstack(s);
    sortedinsert(s,num);
}
int main()
{
    string input;
    getline(cin, input);
    stack<int> s;
    stringstream ss(input);
    int data;

    while (ss >> data)
    {
        s.push(data);
    }
    cout << "element in stake is :\n";
    print(s);
    reversestack(s);
    cout<<"\nafter revers the stck;\n";
    print(s);
sortstack(s);
    cout<<"after sort the stake is :\n";
    print(s);
    return 0;
}