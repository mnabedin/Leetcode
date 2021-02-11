# Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

# Example 1:

# Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
# Output: 6
# Explanation: [4,-1,2,1] has the largest sum = 6.
# Example 2:

# Input: nums = [1]
# Output: 1
# Example 3:

# Input: nums = [0]
# Output: 0
# Example 4:

# Input: nums = [-1]
# Output: -1

# Leetcode 53: https://leetcode.com/problems/maximum-subarray/
# Difficulty: Easy

# Kadane's Algorithm
def maxSubArray(self, nums: List[int]) -> int:
    if len(nums) == 1:
        return nums[0]

    # Initialize local and global maximum subarrays
    globalMax = localMax = float('-inf')

    for num in nums:
        # localMax becomes the max of the current num and current num + localMax
        localMax = max(num, localMax + num)
        # globalMax becomes the max of globalMax and localMax
        globalMax = max(globalMax, localMax)

    return globalMax

# Time Complexity: O(N)
# Space Complexity: O(N)
