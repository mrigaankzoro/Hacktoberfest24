#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void countingSort(vector<int>& arr) {
    if (arr.empty()) return;

    // Find the minimum and maximum element in the array
    int minElement = *min_element(arr.begin(), arr.end());
    int maxElement = *max_element(arr.begin(), arr.end());

    int range = maxElement - minElement + 1;

    // Create a count array to store the count of each unique element
    vector<int> count(range, 0);
    
    // Store the count of each element
    for (int i = 0; i < arr.size(); i++) {
        count[arr[i] - minElement]++;
    }

    // Overwrite the original array with sorted elements
    int index = 0;
    for (int i = 0; i < range; i++) {
        while (count[i]--) {
            arr[index++] = i + minElement;
        }
    }
}

int main() {
    vector<int> arr = {4, 2, -1, 0, 5, -2, 3, -2, 4};
    
    countingSort(arr);

    cout << "Sorted array: ";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    
    return 0;
}
