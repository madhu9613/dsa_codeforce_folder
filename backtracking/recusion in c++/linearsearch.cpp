#include <iostream>
using namespace std;
int lsearch(int *arr, int *where, int n, int key, int index, int *count)
{
    if (n == 0)
    {
        return *count;
    }

    if (arr[0] == key)
    {
        where[*count] = index;
        (*count)++;
    }
    return lsearch(arr + 1, where, n - 1, key, index + 1, count);
}
int main()
{

    int n;
    cin >> n;
    int *arr = new int[n]; // dynamically allocating  memory to store the array;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int key;
    cout << "enter element to be find" << endl;
    cin >> key;
    int *where = new int[n]; // for store the indexs where key found;
    int count = 0;
    int index = 1;
    int occurance = lsearch(arr, where, n, key, index, &count);
    if (occurance < 1)
    {
        cout << "element not found" << endl;
    }
    else
    {
        cout << "element found at position(s) :>" << endl;
        for (int i = 0; i < count; i++)
        {
            cout << where[i];
            if (i < count - 1)
            {
                cout << ",";
            }
        }
        cout << endl;
        cout << key << " occure " << count << " times" << endl;
    }

    delete[] arr;
    delete[] where;
    ;
    return 0;
}