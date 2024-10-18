#include <iostream>
using namespace std;

// A function to heapify the array.
void MaxHeapify(int a[], int i, int n) {
    int largest = i; // Initialize largest as root
    int left = 2 * i + 1; // left = 2*i + 1
    int right = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (left < n && a[left] > a[largest]) {
        largest = left;
    }

    // If right child is larger than largest so far
    if (right < n && a[right] > a[largest]) {
        largest = right;
    }

    // If largest is not root
    if (largest != i) {
        swap(a[i], a[largest]); // Swap root with largest
        MaxHeapify(a, largest, n); // Recursively heapify the affected sub-tree
    }
}

void HeapSort(int a[], int n) {
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--) {
        MaxHeapify(a, i, n);
    }

    // One by one extract elements from heap
    for (int i = n - 1; i >= 0; i--) {
        swap(a[0], a[i]); // Move current root to end
        MaxHeapify(a, 0, i); // call MaxHeapify on the reduced heap
    }
}

int main() {
    int n;
    cout << "\nEnter the number of data elements to be sorted: ";
    cin >> n;

    int arr[n]; // Declare array of size n
    for (int i = 0; i < n; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr[i];
    }

    // Perform Heap Sort
    HeapSort(arr, n);

    // Printing the sorted data
    cout << "\nSorted Data: ";
    for (int i = 0; i < n; i++) {
        cout << "-> " << arr[i];
    }
    cout << endl; // New line at the end

    return 0;
}

			

