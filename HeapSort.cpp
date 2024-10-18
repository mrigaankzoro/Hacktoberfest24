#include <iostream>

using namespace std;

// A function to heapify the array.
void MaxHeapify(int a[], int i, int n)
{
    int j, temp;
    temp = a[i];
    j = 2 * i;

    while (j <= n)
    {
        // Check if the right child exists and is greater than the left child
        if (j < n && a[j + 1] > a[j])
            j = j + 1;
        // If parent is already larger, stop heapifying
        if (temp > a[j])
            break;
        else
        {
            a[j / 2] = a[j]; // Move child up
            j = 2 * j;       // Move to the next child
        }
    }
    a[j / 2] = temp;
}

// Function to sort the array using Heap Sort
void HeapSort(int a[], int n)
{
    int i, temp;
    for (i = n; i >= 2; i--)
    {
        // Swap the root (maximum value) with the last element in the heap
        temp = a[i];
        a[i] = a[1];
        a[1] = temp;
        // Rebuild the heap with the remaining elements
        MaxHeapify(a, 1, i - 1);
    }
}

// Function to build the Max-Heap
void Build_MaxHeap(int a[], int n)
{
    int i;
    // Start from the last non-leaf node and heapify each one
    for (i = n / 2; i >= 1; i--)
        MaxHeapify(a, i, n);
}

int main()
{
    int n, i;
    cout << "\nEnter the number of data elements to be sorted: ";
    cin >> n;
    
    // Using 1-based indexing, hence the array size is n+1
    int arr[n + 1];

    // Input the array elements (1-based indexing)
    for (i = 1; i <= n; i++)
    {
        cout << "Enter element " << i << ": ";
        cin >> arr[i];
    }

    // Build the Max-Heap
    Build_MaxHeap(arr, n);
    // Perform Heap Sort
    HeapSort(arr, n);

    // Output the sorted data
    cout << "\nSorted Data: ";
    for (i = 1; i <= n; i++)
        cout << "->" << arr[i];

    return 0;
}
