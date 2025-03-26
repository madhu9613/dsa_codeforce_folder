// output sum of the row element
#include <iostream>

using namespace std;
void rowsum(int arr[][100], int r, int c, int s[100])
{

    cout << "printing row wise  sum" << endl;
    for (int i = 0; i < r; i++)
    {
        s[i] = 0;
        for (int j = 0; j < c; j++)
        {
            s[i] += arr[i][j];
        }
    }
    for (int i = 0; i < r; i++)
    {
        cout << s[i] << " ";
    }
    cout << endl;
}
void colsum(int arr[][100], int r, int c, int C[100])
{

    cout << "printing coloumn wise sum" << endl;
    for (int i = 0; i < c; i++)
    {
        C[i] = 0;
        for (int j = 0; j < r; j++)
        {
            C[i] += arr[i][j];
        }
    }

    for (int i = 0; i < c; i++)
    {
        cout << C[i] << " ";
    }
}
int max(int r, int s[100])

{
    int maxi= s[0];
    for (int i = 1; i < r; i++)
    {
        if (s[i] > maxi)
        {
            maxi = s[i];
        }
    }
    return maxi;
}

int main()
{
    int r, c;

    cout << "enter row and coloumn :" << endl;
    cin >> r >> c;
    int arr[1001][100];
    int s[100], C[100];
    cout << "enter element row wise:" << endl;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> arr[i][j];
        }
    }
    cout << "printing matrix" << endl;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    rowsum(arr, r, c, s);
    colsum(arr, r, c, C);
    int a=max(r,s);
    int b=max(c,C);
    cout<<endl;
    cout<<"maximum row sum"<< a <<" maximum coloumn sum"<< b <<endl;
    return 0;
}