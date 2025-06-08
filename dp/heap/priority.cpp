/*
using priority queue creating heap data structure
by->default its maxheap

*/
#include<iostream>
#include<queue>
#include<sstream>
using namespace std;
int  main()
{
    //maxima heap
    priority_queue<int> pq;
    //creating minima heap:
    priority_queue<int,vector<int> ,greater<int> > minheap;
   string input;
   getline(cin,input);
   stringstream ss(input);
   int data;
   while(ss>> data)
   {
    pq.push(data);
    minheap.push(data);
   }
cout<<"for maxima heap"<<endl;
cout<<"element at top is "<<pq.top();
//traversing in pq
cout<<"printing it" <<endl;
while(!pq.empty())
{
    cout<<pq.top()<<" ";
    pq.pop();
}

cout<<"minima heap"<<endl;
cout<<"element at top is "<<minheap.top();
//traversing in minheap
cout<<"printing it" <<endl;
while(!minheap.empty())
{
    cout<<minheap.top()<<" ";
    minheap.pop();
}
    return 0;
}