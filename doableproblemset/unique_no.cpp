//programme to count each douplicate number once like a set:":"
#include <iostream>
#include <set>
#include <vector>
using namespace std;
int main() {
    vector<int> arr = {1, 2, 3, 2, 4, 1, 5};
    set<int> uniqueNumbers(arr.begin(), arr.end());

    cout << "Number of unique numbers: " << uniqueNumbers.size() <<endl;

    return 0;
}
