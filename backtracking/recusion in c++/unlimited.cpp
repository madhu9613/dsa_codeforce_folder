#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int main() {
    vector<int> numbers;
    string input;

    cout << "Enter numbers separated by spaces (press Enter to stop):" << endl;

    
    getline(cin, input);

    
    stringstream ss(input);
    int num;

    
    while (ss >> num) {
        numbers.push_back(num);
    }

   
    cout << "You entered:" << endl;
    for (int i = 0; i < numbers.size(); i++) {
        cout << numbers[i] <<" ";
    }

    return 0;
}
