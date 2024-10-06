#include <iostream>
#include <vector>

void insertionSort(std::vector<int>& arr) {
    int n = arr.size();
    
    // Handle empty or single-element arrays
    if (n <= 1) return;

    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Move elements of arr[0..i-1] that are greater than key
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Function to print the array
void printArray(const std::vector<int>& arr) {
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main() {
    // Test cases
    std::vector<int> test1 = {12, 11, 13, 5, 6};
    std::vector<int> test2 = {};
    std::vector<int> test3 = {42};
    std::vector<int> test4 = {1, 2, 3, 4, 5};
    std::vector<int> test5 = {3, 1, 2, 1, 3};

    // Sorting and printing test cases
    std::cout << "Original array 1: ";
    printArray(test1);
    insertionSort(test1);
    std::cout << "Sorted array 1: ";
    printArray(test1);

    std::cout << "Original array 2: ";
    printArray(test2);
    insertionSort(test2);
    std::cout << "Sorted array 2: ";
    printArray(test2);

    std::cout << "Original array 3: ";
    printArray(test3);
    insertionSort(test3);
    std::cout << "Sorted array 3: ";
    printArray(test3);

    std::cout << "Original array 4: ";
    printArray(test4);
    insertionSort(test4);
    std::cout << "Sorted array 4: ";
    printArray(test4);

    std::cout << "Original array 5: ";
    printArray(test5);
    insertionSort(test5);
    std::cout << "Sorted array 5: ";
    printArray(test5);

    return 0;
}
