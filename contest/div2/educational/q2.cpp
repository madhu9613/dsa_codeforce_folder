/*

QUEATION NO 2
*/

#include<bits/stdc++.h>
using namespace std;


int main() {
    int t; // Number of test cases
    cin >> t;

    while (t--) {
        int n,d;
        cin >> n>>d;
        
        set<int> result;
    
        result.insert(1);
        if(d%2!=0)
        {
            result.insert(d);
        }
        
        if(n>=3 || d%3==0)
        {
            result.insert(3);
        }
        if(n>=4 || d%7==0)
        {
            result.insert(7);
        }
        if(n>=6  || d%9==0)
        {
            result.insert(9);
        }
        for(auto i:result)
        {
            cout<<i<<" ";
        }
        cout<<endl;

        
    
       
    }

    return 0;
}
