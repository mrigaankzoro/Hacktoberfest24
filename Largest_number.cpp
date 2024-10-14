// C++ program to find the largest number in an array
// without using std::max_element
// Simplified Version 
#include <iostream>

using namespace std;

int main()
{
    // take input of array size
    int n;
    cin>>n;
    //take input of array
    int arr[n] ;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

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
