#include <iostream>
using namespace std;
int ispresent(int arr[][100], int target, int r, int c, int position[][2])
{
    int count = 0;
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <=c; j++)
        {
            if (arr[i][j] == target)
            {

                position[count][0] = i;
                position[count][1] = j;

                count++;
            }
        }
    }
    return count;
}
void freq(int arr[][100],int r,int c)
{
    int frequnecy[10001]={0};//here i will store frequency of element::
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
          frequnecy[arr[i][j]]++;
          
        }
    }
    cout<<"frequency of each element are :"<<endl;
{
    for(int i=0;i<=10001;i++)
    {
        if(frequnecy[i]>0)
        {
            cout<<"element "<<i<< " :"<<frequnecy[i]<<"times"<<endl;
        }
    }
}
}
int main()
{
    int r, c;

    cout << "enter number of rows and coloumn :" << endl;
    cin >> r >> c;
    int arr[100][100];
    cout << "enter the elements :" << endl;
    for (int i = 1; i <= r; i++)
    {

        for (int j = 1; j <= c; j++)
        {
            cin >> arr[i][j];
        }
    }
    cout << "printing the matrix:" << endl;
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    // i have to search a element in the matrix:
    int position[100][2]; // there will be only 2 coloumn::
    int target;
    cout << "enter element to search: " << endl;
    cin >> target;

    int a = ispresent(arr, target, r, c, position);
    if (a == 0)
    {
        cout << "not found" << endl;
    }
    else
    {
        cout << "element " << target << " found " << a << " times :" << endl;
        cout << "positions are:" << endl;
        for (int i = 0; i < a; i++)
        {
            cout << position[i][0] << " " << position[i][1] << endl;
        }
    }
    freq(arr,r,c);
    return 0;
}