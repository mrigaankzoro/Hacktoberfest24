from typing import List

class Solution:
    def maxArea(self, height: List[int]) -> int:
        max_area = 0
        left = 0
        right = len(height) - 1

        while left < right:
            # Calculate the width and area
            width = right - left
            current_area = width * min(height[left], height[right])
            max_area = max(max_area, current_area)

            # Move the pointers
            if height[left] < height[right]:
                left += 1
            else:
                right -= 1

        return max_area
