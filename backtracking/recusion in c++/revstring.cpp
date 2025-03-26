#include <iostream>
#include <cctype>  // for isalnum function alphanumeric
using namespace std;

void rec(int i, int j, string& str)
{
    // Base condition
    if(i > j)
    {
        return;
    }

    // Skip non-alphanumeric characters from the start
    if(!isalnum(str[i]))
    {
        rec(i + 1, j, str);
        return;
    }

    // Skip non-alphanumeric characters from the end
    if(!isalnum(str[j]))
    {
        rec(i, j - 1, str);
        return;
    }

    // Swap alphanumeric characters (letters and digits)
    swap(str[i], str[j]);

    // Recursive call for the next characters
    rec(i + 1, j - 1, str);
}

int main()
{
    string input;
    getline(cin, input);

    // Remove trailing spaces by adjusting the end index
    int end = input.size() - 1;
    while(end >= 0 && input[end] == ' ')
    {
        end--;  // Skip spaces at the end
    }

    // Perform recursion on the trimmed part of the string
    rec(0, end, input);

    // Output the reversed string, preserving special characters and spaces
    cout << input << endl;

    return 0;
}
