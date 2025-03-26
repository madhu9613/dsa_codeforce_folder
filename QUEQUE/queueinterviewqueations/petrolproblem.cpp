//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};




/*You are required to complete this method*/
class Solution{
  public:
    int tour(petrolPump p[],int n)
    {
       //Your code here
       int deficent=0,balance=0,start=0;
       for(int i=0;i<n;i++)
       {
        balance+=p[i].petrol-p[i].distance;
   if(balance<0)
   {
     deficent+=balance;
     start=i+1;
     balance=0;

   }

       }
       if(deficent+balance>=0)
       {
        return start;
       }
       else{
        return -1;
       }
    }
};





int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        petrolPump p[n];
        for(int i=0;i<n;i++)
            cin>>p[i].petrol>>p[i].distance;
        Solution obj;
        cout<<obj.tour(p,n)<<endl;
    
cout << "~" << "\n";
}
}
