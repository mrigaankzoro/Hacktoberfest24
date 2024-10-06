#include <vector>
#include <unordered_map>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map; // Create a hash map to store number-index pairs
        
        for(int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            
            // If complement exists in map, we found our pair
            if(map.find(complement) != map.end()) {
                return {map[complement], i};
            }
            
            // Store the current number and its index
            map[nums[i]] = i;
        }
        
        return {}; // Return empty vector if no solution found
    }
};