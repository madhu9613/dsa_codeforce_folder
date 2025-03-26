#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Function to check if a number is prime
bool isprime(int n) {
    if (n <= 1)
        return false;
    if (n == 2 || n == 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        if(k<=4)
        {
            cout<<-1<<endl;
        }else{
        vector<int> result;
        for (int i = 2; i <= k; i+=2) {
            result.push_back(i);
        }
        int s,count=0;
      if(k%2==0)
      {
       s=k;
       
      } 
      else{
        s=k-1;
        
      }      
        
        // while (isprime(s)) {
        //     ++s;
        //     count++;
        // }
        for(int i=1;i<=k;i+=2)
        {
            if(!isprime(s+i)){
                
                count=i;
               
                break;
            }

        }
        result.push_back(count);
        for(int i=1;i<=k;i+=2)
        {
            if(i!=count)
            {
                result.push_back(i);
            }
        }

        for(int i:result )
        {
            cout<<i<<" ";
        }
        cout << endl;
    }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
