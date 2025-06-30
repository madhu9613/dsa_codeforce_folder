/*

You are given timings of n meetings in the form of (start[i], end[i]) where start[i] is
 the start time of meeting i and end[i] is the finish time of meeting i. Return the maximum number of meetings that can be accommodated in a single meeting room, when only one meeting can be held in the meeting room at a particular time. 

Note: The start time of one chosen meeting can't be equal to the end time of the other chosen meeting.

thought:to maximize the number of count i will first attend wich will finish first ...after it
1, 3, 0, 5, 8, 5], end[] =  [2, 4, 6, 7, 9, 9]
*/
#include<bits/stdc++.h>
using namespace std;
bool compare(pair<int,int> a, pair<int,int> b)
{
    return a.second<b.second;
}
int main()
{
    int n;
    cin>>n;
    vector<pair<int,int> > meeting;
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        meeting.push_back(make_pair(a,b)); //first is starting point and second is ending point

    }
    sort(meeting.begin(),meeting.end(),compare);
    
   int count=1;
   int meetend=meeting[0].second;

   for(int i=1;i<n;i++)
   {
         if(meetend < meeting[i].first)
         {
            count++;
            meetend=meeting[i].second;
         }
        
   }
   cout<<count<<endl;


}