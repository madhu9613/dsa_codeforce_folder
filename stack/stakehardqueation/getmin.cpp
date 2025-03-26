#include <iostream>
#include <stack>
#include <climits>  // For INT_MAX
using namespace std;

int minValue(int a, int b) {
    return a > b ? b : a;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    
    stack<int> number;
    stack<int> getmin;
    int minimum = INT_MAX;

    for (int i = 0; i < n; i++) {
        int data;
        cin >> data;
        number.push(data);
        minimum = minValue(minimum, data);
        getmin.push(minimum);
    }
 while(!getmin.empty())
 {
    cout<<getmin.top()<<" ";
    getmin.pop();
 }
  
    return 0;
}
