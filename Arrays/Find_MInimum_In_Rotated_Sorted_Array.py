# Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:

# [4,5,6,7,0,1,2] if it was rotated 4 times.
# [0,1,2,4,5,6,7] if it was rotated 7 times.
# Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

# Given the sorted rotated array nums of unique elements, return the minimum element of this array.

# Example 1:

# Input: nums = [3,4,5,1,2]
# Output: 1
# Explanation: The original array was [1,2,3,4,5] rotated 3 times.

# Leetcode 153: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
# Difficulty: Medium

# Solution: Realize that the minimum will always be in the unsorted side of the array so we adjust left and right boundaries
# accordingly


def findMin(self, nums: List[int]) -> int:
    # Only one element in array, return it
    if len(nums) == 1:
        return nums[0]

    left, right = 0, len(nums) - 1

    # left, right both converge to minimum
    # Not <= because that would loop forever
    while left < right:

        # Prevents integer overflow
        midpoint = left + (right - left) // 2

        # Minimum is in unsorted side of array. We know pivot must be to the right becuase the values wrapped around and
        # became smaller. Example: [3,4,5,6,7,8,9,1,2]. We know that there is at least one value smaller than the midpoint to the
        # right so we never have to consider the midpoint again.
        if nums[midpoint] > nums[right]:
            left = midpoint + 1

        # Here, nums[midpoint] <= nums[right]. The pivot must be at midpoint or to the left of it as the values didn't wrap
        # around and become smaller. Example: [8,9,1,2,3,4,5,6,7]. If nums[midpoint] <= nums[right], numbers continued to increase
        # to the right of midpoint. However midpoint might still hold the minimum value so we set right to midpoint
        else:
            right = midpoint

    # At this point, left and right converge to a single index (for minimum value) since our if/else forces the bounds
    # of left/right to shrink each iteration.
    return nums[left]


# Time Complexity: O(logN)
# Space Complexity: O(1)