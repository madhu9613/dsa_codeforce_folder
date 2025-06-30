/*
there are n types of candey avilable in a shop you can buy one candey and you will get k candey for free

find minimum and maxima number of money required to buy all candey

*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    vector <int> candey;
    for(int i=0;i<n;i++)
    {
        int c;
        cin>>c;
        candey.push_back(c);
    }
    sort(candey.begin(),candey.end());
   
   int price=0;
   
   while(!candey.empty())
   {
    price+=candey[0];
    candey.erase(candey.begin());
    for(int i=0;i<k;i++)
    {
        candey.pop_back();
    }
    
   }
cout<<price<<endl;
    return 0;
}