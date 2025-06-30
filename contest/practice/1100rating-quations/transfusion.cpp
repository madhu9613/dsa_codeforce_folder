/*
choose i from 2 to n-1 
ai-1 dec by 1 and ai+1 inc by 1
or ai+1 inc by and ai-1 by 1 

for 1 2 3 4 5 
if i =2
After each operation, all the values must be non-negative. Can you make all the elements equal after any number of operations?

*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        int s=0;
        for(int i=0;i<n;i++)
        {
            int data;
           cin>>data;   
            s+=data;
        }
        if(s%n==0)
        {
            cout<<"yes"<<endl;
        }
        else{
            cout<<"no"<<endl;
        }

    }
    return 0;
}