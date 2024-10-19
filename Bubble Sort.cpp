#include <iostream>
using namespace std;

// Function to perform Bubble Sort
void BubbleSort(int arr[], int n) {
    // Loop through each element in the array
    for (int k = 0; k < n - 1; k++) {
        // Perform a pass through the array
        for (int i = 0; i < n - k - 1; i++) {
            // Compare adjacent elements
            if (arr[i] > arr[i + 1]) {
                // Swap if they are in the wrong order
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
    }

    // Output the sorted array
    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl; // New line after printing the array
}

int main() {
    int arr[6] = {10, 1, 7, 6, 14, 9};
    int size = sizeof(arr) / sizeof(arr[0]); // Calculate the size of the array

    BubbleSort(arr, size); // Call the BubbleSort function
    return 0; // Indicate successful completion
}
