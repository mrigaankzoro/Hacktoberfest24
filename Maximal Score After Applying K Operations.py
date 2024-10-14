# Question:

# You are given a 0-indexed integer array nums and an integer k. You have a starting score of 0.

# In one operation:

# 1:choose an index i such that 0 <= i < nums.length,
# 2:increase your score by nums[i], and
# 3:replace nums[i] with ceil(nums[i] / 3).
# 4:Return the maximum possible score you can attain after applying exactly k operations.

# The ceiling function ceil(val) is the least integer greater than or equal to val.

 

# Example 1:

# Input: nums = [10,10,10,10,10], k = 5
# Output: 50
# Explanation: Apply the operation to each array element exactly once. The final score is 10 + 10 + 10 + 10 + 10 = 50.


# Solution :

class Solution:
    def maxKelements(self, nums: List[int], k: int) -> int:
        
        heap =[]

        for i in nums:

            heapq.heappush(heap , -1 * i)

        score = 0

        while k != 0:

            val = -1*heapq.heappop(heap)

            score += val

            heapq.heappush(heap , -1 * (math.ceil(val/3)))

            k -= 1

        return score