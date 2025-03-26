#include <iostream>
#include <vector>
using namespace std;
int lsearch(int *arr, int n, int key, vector<int> &where)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            where.push_back(i);
            count++;
        }
    }
    return count;
}
int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int key;
    cout << "enter element to be found>" << endl;
    cin >> key;
    vector<int> where;

    int occurance=lsearch(arr,n,key,where);
    if(occurance<1)
    {
        cout<<"element not found";
    }
    else{
        cout<<"element found at the indexes>"<<endl;
        for(int i=0;i<where.size();i++)
        {
            cout<<where[i];
            if(i<where.size()-1)
            {
               cout<<",";
            }
        }cout<<endl;
      cout<<key<<" occure "<<occurance<<" times";
    }
    return 0;
}