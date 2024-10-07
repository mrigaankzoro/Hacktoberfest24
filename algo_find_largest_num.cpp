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
using namespace std;

int main() {
    int n;

    // Input number of elements
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];

    // Input array elements
    cout << "Enter the elements of the array: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Initialize max with the first element
    int max = arr[0];

    // Loop through the array to find the largest element
    for(int i = 1; i < n; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
    }

    // Output the largest element
    cout << "The largest number is: " << max << endl;

    return 0;
}
