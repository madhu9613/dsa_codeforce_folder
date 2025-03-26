#include<iostream>
#include<unordered_map>
#include<queue>
using namespace std;
string solve(string input)
{
    queue<char> q;
 
    unordered_map<char,int> count; //to store frequency of numbers
   string result="";
   for(char ch: input)
   {
    
    count[ch]++;
    if(count[ch]==1)
    {
        q.push(ch);
    }
    while(!q.empty())
    {
        if(count[ch]>1)
        {
            q.pop();
        }
        else{
            result.push_back(q.front());
            break;
        }
    }
    if(q.empty())
    {
        result.push_back('#');
    }


   }
   return result;

}
int main()
{
    string input;
    getline(cin,input);
   string result= solve(input);
   cout<<result;
    return 0;
}