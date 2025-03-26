/*
 Given an array, arr[] of rope lengths, connect all ropes into
 a single rope with the minimum total cost.
 The cost to connect two ropes is the sum of their lengths.
*/
#include <bits/stdc++.h>
using namespace std;

int solve(int arr[], int n)
{
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < n; i++)
    {
        pq.push(arr[i]);
    }

    int ans = 0; 

    while (pq.size() > 1)
    {
        int a = pq.top(); 
        pq.pop();
        int b = pq.top(); 
        pq.pop();

        int cost = a + b; // Cost to connect the two ropes
        ans += cost;      // Add the cost to the total
        pq.push(cost);    // Insert the new rope back into the heap
    }

    return ans;
}

int main()
{
    int n;
    cout << "Enter the number of ropes: ";
    cin >> n;

    int *arr = new int[n]; // Dynamically allocate array
    cout << "Enter the lengths of the ropes: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int ans = solve(arr, n); // Pass array and its size to the function
    cout << "Minimum cost to connect ropes is: " << ans << endl;

    delete[] arr; // Free the allocated memory
    return 0;
}
