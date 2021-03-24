# Given an integer array nums, return true if there exists a triple of indices (i, j, k) such that i < j < k and nums[i] < nums[j] < nums[k].
# If no such indices exists, return false.

# Example:

# Input: nums = [2,1,5,0,4,6]
# Output: true
# Explanation: The triplet (3, 4, 5) is valid because nums[3] == 0 < nums[4] == 4 < nums[5] == 6.

# Leetcode 334: https://leetcode.com/problems/increasing-triplet-subsequence/
# Difficulty: Medium

# Solution: Keep track of the first, and second smallest numbers we've seen in an increasing subsequence and return True if we find a third

def increasingTriplet(self, nums: List[int]) -> bool:
    # Variables to keep track of first and second smallest numbers in subsequence
    first = second = float('inf')

    for num in nums:
        # If there's a new smallest number, start a new subsequence
        if num <= first:
            first = num
        # Smaller than or equal to second smallest number, but larger than smallest number
        elif num <= second:
            second = num
        # We found a number larger than first and second so we have an increasing triplet subsequence
        else:
            return True

    # We haven't found an increasing triplet subsequence
    return False

# Time Complexity: O(N)
# Space Complexity: O(1)
