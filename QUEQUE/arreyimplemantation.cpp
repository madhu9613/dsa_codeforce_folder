#include<iostream>
using namespace std;
class queue{

int* arr;
int front;
int rear;
int size;
public:
queue()
{
int size=100001;
arr=new int[size];
front=rear=0;

}
bool isempty()
{
if(front==rear)
{
    return true;
}
else{
    return false;

}
}
void enqueue(int data) 
{
    if(rear==size)
    {
        cout<<"queue is full\n";
    }
    else{

        arr[rear++]=data;
    }
}
int dequeue()
{
    if(isempty())
    {
       return -1;
    }
    else{
        int ans=arr[front];
        arr[front++]=-1;
        if(front==rear)
        {
            front=rear=0;
        }
        return ans;

    }
}
int front()
{
    if(front==rear)
    {
        return -1;
    }
    else{
      return  arr[front];
    }
}

};
int main()
{
    return 0;
}