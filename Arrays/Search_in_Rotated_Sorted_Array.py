# There is an integer array nums sorted in ascending order (with distinct values).

# Prior to being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length)
# such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed).
# For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

# Given the array nums after the rotation and an integer target, return the index of target if it is in nums,
# or -1 if it is not in nums.

# Example 1:
# Input: nums = [4,5,6,7,0,1,2], target = 0
# Output: 4

# Example 2:
# Input: nums = [4,5,6,7,0,1,2], target = 3
# Output: -1

# Leetcode 33: https://leetcode.com/problems/search-in-rotated-sorted-array/
# Difficulty: Medium

# Solution: Find index of min element in list, then use that to set left and right boundaries for a regular binary search

def search(self, nums: List[int], target: int) -> int:
    if len(nums) == 0:
        return -1

    # Find minimum in rotated sorted array
    def minBinarySearch(nums):
        left, right = 0, len(nums) - 1

        while left < right:
            mid = left + (right - left) // 2
            if nums[mid] > nums[right]:
                left = mid + 1
            else:
                right = mid

        return left

    start = minBinarySearch(nums)
    left, right = 0, len(nums) - 1

    # If target is within start and right, set left to start and vice versa for right
    if target >= nums[start] and target <= nums[right]:
        # e.g: [4,5,6,7,0,1,2] if target is 1, target is within the start and right boundaries inclusive
        # so left of binary search is index of 0 (min element)
        left = start
    else:
        right = start

    # Regular binary searcg
    while left <= right:
        mid = left + (right - left) // 2

        if nums[mid] < target:
            left = mid + 1
        elif nums[mid] > target:
            right = mid - 1
        else:
            return mid

    return -1

# Time Complexity: O(logN)
# Space Complexity: O(1)
