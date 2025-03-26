//always search a base case:
//0 1 1 2 3 5 8 13

#include<iostream>
using namespace std;
int fibo(int n)
{
    if(n==0)
      return 0;
    if(n==1)
      return 1;
      //return 
    
    return fibo(n-1)+fibo(n-2);

}
int main()
{
    int ans =fibo(8);
    cout<<ans;
    return 0;
}