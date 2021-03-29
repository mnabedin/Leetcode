# Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent,
# with the colors in the order red, white, and blue.

# We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

# Example 1:

# Input: nums = [2,0,2,1,1,0]
# Output: [0,0,1,1,2,2]

# Leetcode 75: https://leetcode.com/problems/sort-colors/
# Difficulty: Medium

# Solution: Keep low (0), mid (1) and high (2) pointers and swap values while iterating though the list

def sortColors(self, nums: List[int]) -> None:
    """
    Do not return anything, modify nums in-place instead.
    """
    low, mid, high = 0, 0, len(nums) - 1

    while mid <= high:
        # Swap the current value with the low pointer if we encounter a zero and increment both pointer
        if nums[mid] == 0:
            nums[mid], nums[low] = nums[low], nums[mid]
            low += 1
            mid += 1
        # Else if we encounter a one, it's where it should be so just increment mid
        elif nums[mid] == 1:
            mid += 1
        # Else we encountered a two, so swap with the high pointer and decrement just high becase we still want to process mid
        # after the swap
        else:
            nums[mid], nums[high] = nums[high], nums[mid]
            high -= 1

# Time Complexity: O(N)
# Space Complexity: O(1)
