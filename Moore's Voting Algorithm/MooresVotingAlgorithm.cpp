#include <iostream>
#include <vector>

int findMajorityElement(const std::vector<int>& nums) {
    int candidate = -1;
    int count = 0;

    // Phase 1: Find the candidate
    for (int num : nums) {
        if (count == 0) {
            candidate = num;
            count = 1;
        } else if (num == candidate) {
            count++;
        } else {
            count--;
        }
    }

    // Phase 2: Verify the candidate
    count = 0;
    for (int num : nums) {
        if (num == candidate) {
            count++;
        }
    }

    // Check if candidate is actually the majority
    if (count > nums.size() / 2) {
        return candidate;
    } else {
        return -1; // Indicating no majority element
    }
}

int main() {
    std::vector<int> nums = {3, 2, 3};
    int majorityElement = findMajorityElement(nums);

    if (majorityElement != -1) {
        std::cout << "The majority element is: " << majorityElement << std::endl;
    } else {
        std::cout << "No majority element found." << std::endl;
    }

    return 0;
}
