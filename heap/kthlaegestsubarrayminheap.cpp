#include <iostream>
using namespace std;

// make priority queue code implemantation
/*min heap*/
void heapify(int arr[], int n, int i)
{
    int smallest = i;
    int leftchild = 2 * i + 1;
    int rightchild = 2 * i + 2;
    if (leftchild < n && arr[leftchild] < arr[smallest])
    {
        // swap(arr[leftchild],arr[smallest]);
        smallest = leftchild;
    }

    if (rightchild < n && arr[rightchild] < arr[smallest])
    {
        // swap(arr[rightchild],arr[smallest]);
        smallest = rightchild;
    }
    if (smallest != i)
    {
        swap(arr[i], arr[smallest]);
        heapify(arr, n, smallest);
    }
}
// building heap...
void buildheap(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
}
// .......to insert element in heap as a minheapproperty

void insertHeap(int heap[], int &size, int value)
{
    heap[size] = value;
    size++;

    int i = size - 1;
    while (i != 0 && heap[(i - 1) / 2] > heap[i])
    {
        swap(heap[i], heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}
// or remove top from pq and restore the minheap property
void removeMin(int heap[], int &size)
{
    if (size <= 0)
        return;
    if (size == 1)
    {
        size--;
        return;
    }

    heap[0] = heap[size - 1];
    size--;
    heapify(heap, size, 0);
}

int main()
{

    int n;
    cin >> n;
    int nums[n];
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    int k;
    cin >> k;

    int heap[k];
    int heapSize = 0;

    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += nums[j];

            if (heapSize < k)
            {
                insertHeap(heap, heapSize, sum);
            }
            else if (sum > heap[0])
            {
                heap[0] = sum;
                heapify(heap, heapSize, 0);
            }
        }
    }

    cout << heap[0] << endl; // The root of the heap contains the k-th largest sum
    return 0;
}
