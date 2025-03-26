#include<iostream>
using namespace std;
class stack{


int *arr;
int top;
int size;
public:
stack(int size)
{
    this->size=size;
    arr=new int[size];
    top=-1;
}
void push (int element)
{
    if(size-top>1)
    {
        top++;
        arr[top]=element;
    }
    else{
        cout<<"stack overflow\n";
    }
}
void pop()
{
    if(top>=0)
    {
        top--;
    }
    else{
        cout<<"stack underflow\n";
    }
} 
int peek()
{
    if(top>=0)
    return arr[top];
    else{
        cout<<"stack is underflow\n";
        return -1;
    }
}
bool empty()
{
    if(top==-1)
    {
        return true;
    }
    else{
        return false;
    }
}
void print()
{
    while(!empty())
    {
        cout<<peek()<<" ";
       pop();
    }
    cout<<endl;
}
};
int main()
{
    stack s(5);
    s.push(4);
    s.push(3);
    s.push(2);
    s.push(1);
    s.push(0);
    s.print();
    return 0;
}