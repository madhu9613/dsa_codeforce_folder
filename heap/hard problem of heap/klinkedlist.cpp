/*

....you are given k list as a input you have to find smallest range [a,b] such
that at least one element from each list exist in the given range ...>
 
 ****
   let,n=element in range
       k=total list;
 ****
 brute force method:->
 --------------------------
  find all possible range from each element
  and store the minimum range and update accordingly...>
  ...complexity will be (nk)^2

optimization using minheap->
---------------------------------
 store first element of each list in the heap find current range let say we
 found the range as [1,5]...here we have two option increse the minima and dec
 the maxima ...but but condition we can  not decrease the maxima for the case
 because at least one should be from the range as 5 is minima for a given list
 means maxima can only inc...
 so we find next element of the minima that we have found from the previous pointer
 and again find range if range is smallest store it..
 repeat the process till pq.empty();
 if(we can;t add more element the break it);list exhausted
 
*/
#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    int aidx; // represent arrey index
    int eidx; // represent element index
    node(int data,int aidx, int eidx)
    {
        this->data=data;
        this->aidx=aidx;
        this->eidx=eidx;
    }

};
class compare{
public:
bool operator() (node* a,node* b)
{
    return a->data > b->data;
}
};
int findsmallestrange(vector< vector<int> > karrey,int k,int n)
{
 int mini=INT_MAX; int maxi=INT_MIN;
 //create a minheap
 priority_queue<node*,vector<node*> ,compare > pq;
 for(int i=0;i<k;i++)
 {
    node* temp=new  node(karrey[i][0],i,0);
    pq.push(temp);
    int maxi=max(maxi,karrey[i][0]);
    int mini=min(mini,karrey[i][0]);
 }
 //process the heap
//  ....storing the starting elements

  int start=mini; int end=maxi;
 while(!pq.empty())
 {
     node*  element=pq.top();
     int mini=element->data;
     pq.pop();
     //if we find minima range then stroe it;   
     if(maxi-mini<end-start)
     {
          start=mini;
          end=maxi;

     }
     //element exist....
     if(element->eidx+1<n)
     {
          node* next=new node(karrey[element->aidx][element->eidx+1],element->aidx,element->eidx);
          pq.push(next);

     }  else{
        break;
     }
     
    
 }
 return (end-start+1);
}
int main()
{

    return 0;
}