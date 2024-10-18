#include <iostream>
#include <vector>

// Function to heapify a subtree rooted at index 'i' which is an index in 'arr[]'.
// n is the size of the heap
void heapify(std::vector<int>& arr, int n, int i) {
    int largest = i; // Initialize largest as root
    int left = 2 * i + 1; // left child index
    int right = 2 * i + 2; // right child index

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
        std::swap(arr[i], arr[largest]); // Swap root and largest

        // Recursively heapify the affected subtree
        heapify(arr, n, largest);
    }
}

// Main function to implement HeapSort
void heapSort(std::vector<int>& arr) {
    int n = arr.size();

    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // One by one extract an element from heap
    for (int i = n - 1; i >= 0; i--) {
        // Move current root to end
        std::swap(arr[0], arr[i]);

        // Call heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

// Function to print an array
void printArray(const std::vector<int>& arr) {
    for (int val : arr) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

int main() {
    int size;

    // Prompt user for the size of the array
    std::cout << "Enter the number of elements in the array: ";
    std::cin >> size;

    // Declare the vector to hold the input values
    std::vector<int> arr(size);

    // Input the array elements from the user
    std::cout << "Enter " << size << " elements:" << std::endl;
    for (int i = 0; i < size; i++) {
        std::cin >> arr[i];
    }

    std::cout << "Original array: ";
    printArray(arr);

    heapSort(arr);

    std::cout << "Sorted array: ";
    printArray(arr);

    return 0;
}
