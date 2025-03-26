#include<bits/stdc++.h>
using namespace std;
void solve(string digit, int index , string output, vector<string> &ans,string mapping[])
{


    if(index>=digit.length())
    {
        ans.push_back(output);
        return ;
    }
     int number=digit[index]-'0'; //convert to integer;
     string value=mapping[number];
     for(int i=0;i<value.length();i++)
     {

        output.push_back(value[i]);
        solve(digit,index+1,output,ans,mapping);
        output.pop_back();
     }

}
int main()
{
    string digit;
    getline(cin,digit);

    string output;
    string mapping[10]={" "," ","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    
    vector< string> ans;
    solve(digit,0,output,ans,mapping);

for(auto it: ans)
{
    cout<<it<<endl;
}
    
    return 0;
}