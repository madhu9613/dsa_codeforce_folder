 // in a sorted arey you have to find elements first occurence and last occurence / if it does not exit return -1;

 //arrey can have duplicate arrey
 #include<iostream>
 using namespace std;
 int first_occurenxce(int arr[], int n, int key) {
    int low = 0;
    int high = n - 1;
    int ans =-1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if(arr[mid]==key)
        {
          ans=mid;
          high=mid-1;
        }
        else if (arr[mid]<key)
        {
            low=mid+1;
            /* code */
        }
        else if (arr[mid]>key)
        {
           high=mid-1;
            /* code */
        }
        
    }

    return ans;  // Key not found, return -1
}
int last_occurrence(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    int ans = -1;
    
    while (low <= high) {
        int mid = (low + high) / 2;
        
        if (arr[mid] == key) {
            ans = mid;
            low = mid + 1; // Move right to find the last occurrence
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    
    return ans; // Return the index of the last occurrence or -1 if not found
}
pair<int, int> find_first_and_last_occurrence(int arr[], int n, int key) {
    pair<int, int> p;
    p.first = first_occurrence(arr, n, key);  // Get first occurrence
    p.second = last_occurrence(arr, n, key);  // Get last occurrence
    return p;
}
int main()
{
    int even[11]={1,2,3,3,3,3,3,3,3,3,5};
    // cout<<"first occurence of 3 is : "<<first_occurenxce(even,11,3);
    // cout<<"last occurence of 3 is : "<<last_occurrence(even,11,3);
     pair<int, int> occurrences = find_first_and_last_occurrence(arr, 11, key);
    cout<<p;
}