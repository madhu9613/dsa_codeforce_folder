#include <iostream>
#include <vector>
void sum(vector<int> &a, int n, vector<int> &b, int m)
{
    vector<int> ans;
    int carry = 0;
    int i = n - 1;
    int j = m - 1;
    while (i >= 0 && j >= 0)
    {
        int v1 = a[i];
        int v2 = b[j];
        int sum = v1 + v2 + carry;
        int carry = sum / 10;
        sum = sum % 10;
        ans.push_back(sum);
        i--;
        j--;
    }
    while (i >= 0)
    {
        sum = a[i] + carry;
         int carry = sum / 10;
        sum = sum % 10;
        ans.push_back(sum);
        i--;
    }
    while(j>=0)
    {
        sum=b[j]+carry;
        int carry = sum / 10;
        sum = sum % 10;
        ans.push_back(sum);
        j--;

    }
}
using namespace std;
int main()
{

    return 0;
}