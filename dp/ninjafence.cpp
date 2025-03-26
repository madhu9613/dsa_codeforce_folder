/* 

lets see 
 there are n posts you have to color them with k color such that not more than two conjecutive [post] has same color

 for same 
 last two has k-1 option different from n-2th and if last two has different last has k-1 and dif from n-1

 recursion become :
  (k-1)*f(n-2)+ (k-1)*f(n-1);

*/
#include<bits/stdc++.h>
using namespace std;
int solve(int n, int k)
{

    if(n==1)
    {

        return k;
    }
    if(n==2)
    {
        return k*k;
    }


    return (k-1)*(solve(n-2,k) +solve(n-1,k) );

}

int main()
{
int n,k;
cin>>n>>k;

int ans=solve(n,k);

cout<<ans;

    return 0;


}