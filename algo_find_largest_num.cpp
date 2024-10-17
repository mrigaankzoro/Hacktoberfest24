/* 
*****************************************************************
                        Algorithm
1. Initialize a variable max with the first element of the array.
2. Loop through the entire array.
3. In each iteration, compare the current element with max.
4. If the current element is greater than max, update max.
5. After the loop, max will hold the largest number in the array. 

*****************************************************************
*/

#include <iostream>
#include <vector>
using namespace std;

// Function to find the largest element in the array
int findLargest(const vector<int>& arr) {
    int max = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
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
    int max = findLargest(arr);

    // Output the largest element
    cout << "The largest number is: " << max << endl;

    return 0;
}

