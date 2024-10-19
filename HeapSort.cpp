#include <iostream>
using namespace std;

// A function to heapify the array.
void maxHeapify(int arr[], int index, int size) {
    int largest = index; // Initialize largest as root
    int leftChild = 2 * index; // Left child index
    int rightChild = 2 * index + 1; // Right child index

    // If left child is larger than root
    if (leftChild <= size && arr[leftChild] > arr[largest]) {
        largest = leftChild;
    }

    // If right child is larger than largest so far
    if (rightChild <= size && arr[rightChild] > arr[largest]) {
        largest = rightChild;
    }

    // If largest is not root, swap and continue heapifying
    if (largest != index) {
        swap(arr[index], arr[largest]);
        maxHeapify(arr, largest, size);
    }
}

void heapSort(int arr[], int size) {
    // Build heap (rearrange array)
    for (int i = size / 2; i >= 1; --i) {
        maxHeapify(arr, i, size);
    }

    // One by one extract elements from heap
    for (int i = size; i >= 2; --i) {
        swap(arr[1], arr[i]); // Move current root to end
        maxHeapify(arr, 1, i - 1); // Call max heapify on the reduced heap
    }
}

int main() {
    int n;
    cout << "\nEnter the number of data elements to be sorted: ";
    cin >> n;
    n++; // Increase to accommodate 1-based indexing
    int arr[n];

    for (int i = 1; i < n; ++i) {
        cout << "Enter element " << i << ": ";
        cin >> arr[i];
    }

    heapSort(arr, n - 1); // Sorting the array

    // Printing the sorted data.
    cout << "\nSorted Data: ";
    for (int i = 1; i < n; ++i) {
        cout << "-> " << arr[i];
    }
    cout << endl;

    return 0;
}
