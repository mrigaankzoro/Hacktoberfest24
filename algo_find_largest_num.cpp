#include <iostream>
#include <vector>
using namespace std;

// Function to find the largest element in the array
int findLargest(const vector<int>& arr) {
    int maxValue = arr[0]; // Use a different name to avoid conflict with standard functions
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] > maxValue) {
            maxValue = arr[i];
        }
    }
    return maxValue;
}

int main() {
    int n;

    // Input number of elements
    cout << "Enter the number of elements: ";
    cin >> n;

    // Check for valid input
    if (n <= 0) {
        cout << "Number of elements must be positive." << endl;
        return 1;
    }

    vector<int> arr(n);

    // Input array elements
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Find the largest element
    int largest = findLargest(arr);

    // Output the largest element
    cout << "The largest number is: " << largest << endl;

    return 0;
}
