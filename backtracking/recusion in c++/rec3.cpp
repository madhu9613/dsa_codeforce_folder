#include <iostream>
using namespace std;

void digitTOnum(int n, string arr[], int& sum) {
    if (n == 0)
        return;

    // Processing
    int digit = n % 10;  // Get the last digit
    n /= 10;             // Remove the last digit

    digitTOnum(n, arr, sum);  // Recursive call to process the next digit
    
    sum += digit;
      // Add the current digit to the sum
      if(sum>=10)
      {
        n=sum;
        digitTOnum(n,arr,sum);
      }
      
    cout << arr[digit] << " ";  // Print the word representation of the digit
    digitTOnum(n, arr, sum); 
}

int main() {
    int n, sum = 0;
    string arr[10] = {
        "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"
    };
    
    cout << "Enter a number: ";
    cin >> n;

    if (n == 0) {
        cout << arr[0] << endl;
        cout << "Sum of digits: " << arr[0] << endl;  // Print the word "zero"
    } else {
        digitTOnum(n, arr, sum);  // Call the function to process the number
        cout << endl;
        cout << "Sum of digits: " << arr[sum] << endl;  // Output the sum as a word
    }

    return 0;
}
