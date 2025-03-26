#include <iostream>
#include<vector>
#include<sstream>
using namespace std;
int bsearch(vector<int>arr,int s,int e,int k)

{
  
    
if(s>e)
{
    return -1;//false
}

int mid=s+(e-s)/2;
if(arr[mid]==k)
{
    return mid; //true
}
if(arr[mid]<k)
{ 
return bsearch(arr,mid+1,e,k);
}
 else{
    return bsearch(arr,s,mid-1,k);
 }

}

int main()
{
  int key;
  vector<int> num;
  string input;
  getline(cin,input);

  stringstream ss(input);
  int n;
  while(ss>>n)
  {
    num.push_back(n);
  }
  cout<<"enter element to be found"<<endl;
  cin>>key;
  int ans=bsearch(num,0,num.size()-1,key);
  if(ans)
  {
    cout<<"element found"<<"at index :> "<<ans;
  }
  else{
    cout<<"not found";
  }
    return 0;
}