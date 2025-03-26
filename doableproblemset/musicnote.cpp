#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;

  while(t--)
{
        int n;
        cin >> n;
        vector<vector<char>> music(n, vector<char>(4)); // Corrected vector declaration

        // Input the matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 4; j++) {
                cin >> music[i][j];
            }
        }

        char ch = '#'; 
        for (int i = n - 1; i >= 0; i--) {
            int c = 0; 

            for (int j = 0; j < 4; j++) {
                c++;
                if (music[i][j] == ch) { 
                    break;
                }
            }
           cout<<c<<" ";
       
    }
}
    return 0;
}