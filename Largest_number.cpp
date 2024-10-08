// C++ program to find the largest number in an array
// without using std::max_element
// Simplified Version 
#include <iostream>

using namespace std;

int main()
{
    // Initialize the array
    int arr[] = { 1, 45, 54, 71, 76, 12 };
    int n = sizeof(arr) / sizeof(arr[0]);

    // Initialize the max_num with the first element of the array
    int max_num = arr[0];

    // Traverse the array to find the largest number
    for (int i = 1; i < n; i++) {
        if (arr[i] > max_num) {
            max_num = arr[i];
        }
    }

    // Output the result
    cout << "Largest number in the array is: " << max_num << endl;

    return 0;
}
