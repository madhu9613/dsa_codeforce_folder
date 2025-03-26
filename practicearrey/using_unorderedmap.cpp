#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int main()
 {
    int n;

    // Input the size of the array
    cout << "Enter the number of elements: ";
    cin >> n;
vector<int> uni;
vector<int>dup;
    vector<int> arr(n);
    unordered_map<int, int> countMap; //to count occurrences

    // Input the elements of the array
    cout << "Enter the elements of the array:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        countMap[arr[i]]++; // Increment the count for each element
    }
    for(const auto& pair :countMap)
    {
        if(pair.second==1)
        {
            uni.push_back(pair.first);
        }
        else{
            dup.push_back(pair.first);
        }

    }
cout<<"unique element are :"<<endl;
for(int i :uni)

{
cout<<i<<"  ";
}
cout<<endl;
cout<<"duplicate elements are :"<<endl;
for(int i: dup)
{
    cout<<i<<" ";
}

}