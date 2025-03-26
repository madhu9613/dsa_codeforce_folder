/*
store a number..remove all odd number from the number and print it;
for example if a number is 45321 answer should be 42;;
*/
#include <iostream>
using namespace std;
void reverse(int a)
{int rev = 0;
    while (a != 0)
    {
        int rem = a % 10;
        
        rev = rev * 10 + rem;
        a = a / 10;
    }
    cout<<rev<<endl;

}
int main()
{
    int  t;
scanf("%d",&t);
while(t--)
{int n, rem = 0, rev = 0;
    cin >> n;
    while (n != 0)
    {
        rem = n % 10;
        if (rem % 2 == 0)

        {
            rev = rev * 10 + rem;
        }
        n = n / 10;
    }
    reverse(rev);
}
    return 0;
}