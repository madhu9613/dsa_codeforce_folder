#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cout << "enter no of element " << endl;

    cin >> n;
    int count;
    vector<int> arr(n);
    vector<bool> visit(n, false);
    vector<int> uni;
    vector<int> dup;
    vector<int> set;
    cout << "enter element of the arey" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout<<"duplicate element and their frequency are"<<endl;
    for (int i = 0; i < n; i++)
    {
        if (!visit[i])
        {
            count = 1;

            for (int j = i + 1; j < n; j++)
            {
                if (arr[i] == arr[j])
                {
                    count++;
                    visit[j] = true;
                }
            }
            cout << arr[i] <<" appear " << count << " times " << endl;
            if(count>1)
            {
               dup.push_back(arr[i]);
            }
            if(count==1)
            {
                uni.push_back(arr[i]);
            }
            set.push_back(arr[i]);
        }
    }

    cout<<"as a set elemen "<<endl;
    for(int i:set)
    {
        cout<<i<<" ";
    }
    cout<<endl;
     cout<<"displaying the unique element arrey "<<endl;
    for(int i:uni)
    {
       cout<<i<<"  ";
    }
    cout<<endl;
    cout<<"displaying the duplicate arrey "<<endl;
    for(int i:dup)
    {
       cout<<i<<"  ";
    }
    
    return 0;
}