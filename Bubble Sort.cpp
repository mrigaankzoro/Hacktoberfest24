#include <iostream>
using namespace std;

void BubbleSort(int arr[], int n) { // Changed return type to void
    int temp = 0;
    for (int k = 0; k < n - 1; k++) {
        for (int i = 0; i < n - k - 1; i++) {
            // No need for j; directly compare arr[i] and arr[i + 1]
            if (arr[i] > arr[i + 1]) {
                // Swap the elements
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
    }
    
    cout << "Sorted Array: " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl; // Add newline for better formatting
}

int main() {
    int arr[6] = {10, 1, 7, 6, 14, 9};
    BubbleSort(arr, 6); // No need to print the return value as it is void
    return 0; // Return 0 to indicate successful execution
}
