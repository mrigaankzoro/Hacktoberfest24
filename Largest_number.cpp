// C++ program to find the largest number in an array
// without using std::max_element
#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
    // Initialize the array
    int arr[] = { 1, 45, 54, 71, 76, 12 };
    int n = sizeof(arr) / sizeof(arr[0]);

    // Find the largest element in the array
    int max_num = *max_element(arr, arr + n);

    // Output the result
    cout << "Largest number in the array is: " << max_num
         << endl;

    return 0;
}
