# Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

# Example:

# Input: [0,1,0,3,12]
# Output: [1,3,12,0,0]

# Note:
# You must do this in-place without making a copy of the array.
# Minimize the total number of operations.

# Leetcode 283: https://leetcode.com/problems/move-zeroes/
# Difficulty: Easy

def moveZeroes(self, nums: List[int]) -> None:
    """
    Do not return anything, modify nums in-place instead.
    """
    # Initialize a pointer to the non zero index
    nonZeroIndex = 0

    for i, v in enumerate(nums):
        # If the element is not a zero
        if v != 0:
            # Swap the current element with the element at nonZeroIndex and increment it
            nums[i], nums[nonZeroIndex] = nums[nonZeroIndex], nums[i]
            nonZeroIndex += 1

# Time Complexity: O(N)
# Space Complexity: O(1)
