#include <iostream>
using namespace std;

// Function to heapify a subtree rooted with node i
void MaxHeapify(int arr[], int n, int i) {
    int largest = i;  // Initialize largest as root
    int left = 2 * i + 1;  // left = 2*i + 1
    int right = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]); // Swap root with largest

        // Recursively heapify the affected subtree
        MaxHeapify(arr, n, largest);
    }
}

// Function to perform Heap Sort
void HeapSort(int arr[], int n) {
    // Build a maxheap
    for (int i = n / 2 - 1; i >= 0; i--) {
        MaxHeapify(arr, n, i);
    }

    // One by one extract elements from heap
    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]); // Move current root to end
        MaxHeapify(arr, i, 0); // call max heapify on the reduced heap
    }
}

// Function to print the array
void PrintArray(int arr[], int n) {
    cout << "Sorted Data: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the number of data elements to be sorted: ";
    cin >> n;
    
    int arr[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr[i];
    }

    HeapSort(arr, n); // Perform heap sort
    PrintArray(arr, n); // Print sorted array

    return 0;
}
