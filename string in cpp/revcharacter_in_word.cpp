#include <iostream>
#include <cstring>

using namespace std;
void reverse(char *start, char *end)
{
  while (start < end)
  {
    swap(*start, *end);
    start++;
    end--;
  }
}
void reverseword(char str[])
{
  int n = strlen(str);
  int start = 0;
    for (int i = 0; i <= n; i++) {
        if (str[i] == ' ' || str[i] == '\0') {
            reverse(str + start, str + i - 1);
            start = i + 1;
        }
    }
}

int main()
{
  char str[100];
  cout << "enter a string " << endl;
  cin.getline(str, 100);
  int n=strlen(str);
  reverse(str+0,str+n-1);
  reverseword(str);
  cout << "after modifying " << str << endl;
  return 0;
}