#include <iostream>
#include<sstream>
using namespace std;

class heap {
public:
    int arr[100];  // Array to store heap elements
    int size = 0;  // Current size of the heap

    // Insert a new value into the heap

    void insert(int value) {
        size += 1;          // Increment heap size
        int index = size;   // Start at the new position
        arr[index] = value; // Place the value at the end of the heap

        // Check and swap with parent if necessary
        while (index > 1) {
            int parent = index / 2;
            if (arr[parent] < arr[index]) { // Max-heap property check
            
                swap(arr[parent], arr[index]);
                index = parent; // Move up to the parent
            } else {
                break; // If parent is larger, stop
            }
        }
    }

    // Print the heap
    void print() {
        for (int i = 1; i <= size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
 void deletenode()
 {
 if(size==0)

 {
    cout<<"nothing to delete "<<endl;
 }
 //last element in the first place
 arr[1]=arr[size];
 size--;
 int index=1;
 while(index<=size)
 {
    int leftchild=2*index;
    int rightchild=2*index+1;
    if(leftchild<=size && arr[index]<arr[leftchild] )
    
    {
        swap(arr[index],arr[leftchild]);
        index=leftchild;

    }

    if(rightchild<=size && arr[index]<arr[rightchild])
    {
        swap(arr[index],arr[rightchild]);
        index=rightchild;
    }

    else{
        return;
    }
 }

 }
};

int main() {
    heap p;

    // Insert elements into the heap
    
    string input;
    getline(cin,input);
    stringstream ss(input);
    int data;
    while(ss>>data)
    {
        p.insert(data);
    }

    // Print the heap
    p.print();

cout<<"after delete "<<endl;
p.deletenode();
p.print();

cout<<"after delete "<<endl;
p.deletenode();
p.print();

cout<<"after delete "<<endl;
p.deletenode();
p.print();
    return 0;
}
