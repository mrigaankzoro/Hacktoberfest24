#include <iostream>
#include <vector>
using namespace std;

int majorityElement(vector<int> nums) {
    int freq = 0, candidate = 0;
    int n = nums.size();
    
    // First pass: Find the candidate using Boyer-Moore Voting Algorithm
    for (int i = 0; i < n; i++) {
        if (freq == 0) {
            candidate = nums[i];
        }
        if (nums[i] == candidate) {
            freq++;
        } else {
            freq--;
        }
    }
    
    // Second pass: Verify if the candidate is actually the majority element
    int count = 0;
    for (int val : nums) {
        if (val == candidate) {
            count++;
        }
    }
    
    if (count > n / 2) {
        return candidate;
    } else {
        return -1; // No majority element found
    }
}

int main() {
    int n;
    
    cout << "Enter the number of votes: ";
    cin >> n;
    
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
    
    if (ans != -1) {
        cout << "The Majority Element is: " << ans << endl;
    } else {
        cout << "No Majority Element found." << endl;
    }

    return 0;
}
