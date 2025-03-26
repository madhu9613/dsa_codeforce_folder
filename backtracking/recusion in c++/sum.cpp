#include <iostream>
using namespace std;

// Function to print digits in words and calculate the sum of digits
void printNumberAndSum(long long n, string arr[], int &sum)
{
    if (n == 0)
        return;

    // Extract the last digit
    int digit = n % 10;
    
cout<<arr[digit]<<" ";

    printNumberAndSum(n / 10, arr, sum);

  
    sum += digit;
}

int reduceToSingleDigit(int sum)
{
    while (sum >= 10)
    {
        int newSum = 0;
        while (sum > 0)
        {
            newSum += sum % 10;
            sum /= 10;
        }
        sum = newSum;
    }
    return sum;
}

int main()
{
    long long n;
    int sum = 0;
    string arr[10] = {
        "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    cout << "Enter a number: ";
    cin >> n;

 
    if (n == 0)
    {
        cout << "Number in words: " << arr[0] << endl;
        cout << "Sum of digit in words: " << arr[0] << endl;
        return 0;
    }

   
    cout << "Number in words: ";
    printNumberAndSum(n, arr, sum);
    cout << endl;

    
    int finalSum = reduceToSingleDigit(sum);

   
    cout << "Sum of digits in words: " << arr[finalSum] << endl;

    return 0;
}
