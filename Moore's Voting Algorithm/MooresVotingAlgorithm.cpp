#include <iostream>
#include <vector>
using namespace std;

// Function to find the majority element in the array
int majorityElement(const vector<int>& nums) {
    int freq = 0, candidate = 0;
    int n = nums.size();
    
    // Finding the candidate for majority element
    for (int i = 0; i < n; i++) {
        if (freq == 0) {
            candidate = nums[i];
        }
        freq += (nums[i] == candidate) ? 1 : -1;
    }
    
    // Verifying if the candidate is indeed the majority element
    int count = 0;
    for (int val : nums) {
        if (val == candidate) {
            count++;
        }
    }
    
    return (count > n / 2) ? candidate : -1; // Return candidate if it's a majority element
}

int main() {
    int n;
    
    cout << "Enter the number of votes: ";
    cin >> n;
    
    // Input validation
    if (n <= 0) {
        cout << "Invalid number of votes. Please enter a positive number." << endl;
        return 1;
    }

    vector<int> nums(n);
    cout << "Enter the votes (numbers separated by space): ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int ans = majorityElement(nums);
    
    // Output the result
    if (ans != -1) {
        cout << "The Majority Element is: " << ans << endl;
    } else {
        cout << "No Majority Element found." << endl;
    }

    return 0;
}
