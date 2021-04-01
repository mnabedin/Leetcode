# Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

# If target is not found in the array, return [-1, -1].

# Follow up: Could you write an algorithm with O(log n) runtime complexity?

# Example 1:

# Input: nums = [5,7,7,8,8,10], target = 8
# Output: [3,4]

# Leetcode 34: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
# Difficulty: Medium

# Solution: Run two lower-bounded binary searches, one for the target and one for the successor of the target


def searchRange(self, nums: List[int], target: int) -> List[int]:
    if not nums:
        return [-1, -1]

    def lowerBinarySearch(target):
        left, right = 0, len(nums) - 1

        while left <= right:
            # Calculate the midpoint
            mid = left + (right - left) // 2

            # This binary search always returns the lower bound of a number because
            # When the current num is lower than the target, left is shifted to the next number right of mid
            # and if current num is greater than or equal to target, it shifts right to the number left of mid
            # this ensures that if numbers are duplicated the search will always narrow into the leftmost number
            if nums[mid] < target:
                left = mid + 1
            else:
                right = mid - 1

        return left

    # Find index of lowest number
    lowerIndex = lowerBinarySearch(target)

    # This finds the index of the first number larger than the target, and then subtracts
    # one from the index it finds which is going to be the rightmost target
    upperIndex = lowerBinarySearch(target + 1) - 1

    # If we didn't go out of bounds in our search and if the number at the lowerIndex actually equals our
    # target (because our binary search will return the next largest number if it didn't exist) we can return the indices
    if lowerIndex < len(nums) and nums[lowerIndex] == target:
        return [lowerIndex, upperIndex]

    return [-1, -1]


# Time Complexity: O(log n)
# Space Complexity: O(n)
