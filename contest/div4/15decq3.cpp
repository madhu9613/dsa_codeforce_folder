/*

QUEATION NO 3
*/
#include<bits/stdc++.h>
using namespace std;

void solve() {
    int t;
    cin >> t;
    while (t--) {
    int m,a,b,c;
    cin>>m>>a>>b>>c;
    int total=2*m;
    int i_can_seat=0;
    //preference for first row 
    if(a<=m ) 
    {
           
       i_can_seat+=a; 

    }
    else{
        // if a>m seat those many how many available::
        i_can_seat+=m;
    }
    //preference for second row
    if(b<=m )
    {
      i_can_seat+=b;
    }
    else{
        i_can_seat+=m;
    }
     //for all c students::
     int vacentseat=total-i_can_seat;
     if(c<=vacentseat)
     {
        i_can_seat+=c;
     }
     else{
        i_can_seat+=vacentseat;
     }

   cout<<i_can_seat<<endl;
    }
}

int main() {
   ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
