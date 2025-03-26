#include <iostream>
#include <string>
#include <vector>
#include <sstream> // For stringstream
using namespace std;

void selection_sort(vector<int>& arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        int minindex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[minindex] > arr[j])
            {
                minindex = j;
            }
        }
        swap(arr[minindex], arr[i]);
    }
}

int main()
{
    vector<int> num;
    string input;

    cout << "Enter numbers separated by '+' (e.g., 1+2+4+9+1):" << endl;
    
    getline(cin, input); // Get the input as a single line
    
    // Use a stringstream to split the input by '+'
    stringstream ss(input);
    string temp;

    while (getline(ss, temp, '+')) // Split by '+'
    {
        // Input validation
        try {
            num.push_back(stoi(temp)); // Convert to integer and add to vector
        } catch (const invalid_argument&) {
            cout << "Invalid input. Please enter valid integers." << endl;
            return 1; // Exit if invalid input is detected
        }
    }

    selection_sort(num); // Sort the numbers

    // Print sorted numbers
    for (size_t i = 0; i < num.size(); i++)
    {
        cout << num[i];
        if (i < num.size() - 1)
        {
            cout << "+"; // Separator
        }
    }
    cout << endl; // End line after output

    return 0;
}
