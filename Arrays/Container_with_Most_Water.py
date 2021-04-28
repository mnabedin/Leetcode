# Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai).
# n vertical lines are drawn such that the two endpoints of the line i is at (i, ai) and (i, 0).
# Find two lines, which, together with the x-axis forms a container, such that the container contains the most water.

# Notice that you may not slant the container.

# Input: height = [1,8,6,2,5,4,8,3,7]
# Output: 49
# Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7].
# In this case, the max area of water (blue section) the container can contain is 49.

# Leetcode 11: https://leetcode.com/problems/container-with-most-water/
# Difficulty: Medium

# Solution: Use two pointers and move inwards keeping track of the maximum area.

def maxArea(self, height: List[int]) -> int:
    # Starting with the widest container so set two pointers to first and last height
    left, right = 0, len(height) - 1
    ans = float('-inf')

    while left < right:
        # Realize that only the minimum height matters as anything higher will cause water to spill
        h = min(height[left], height[right])

        # Calculate area, and update ans
        ans = max(ans, (right - left) * h)

        # Move left pointer inwards if left height is smaller else move right inwards. This is because we want to maximize
        # the height of the container.
        if height[left] < height[right]:
            left += 1
        else:
            right -= 1

    return ans

# Time Complexity: O(N)
# Space Complexity: O(1)
