# Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

# Example 1:

# Input: nums = [-4,-1,0,3,10]
# Output: [0,1,9,16,100]
# Explanation: After squaring, the array becomes [16,1,0,9,100].
# After sorting, it becomes [0,1,9,16,100].

# Leetcode 977: https://leetcode.com/problems/squares-of-a-sorted-array/
# Difficulty: Easy

# Solution: Sorted so use two pointers - realize that after squaring the list converges


def sortedSquares(self, nums: List[int]) -> List[int]:
    # Intialize results list, left and right pointers
    result = [0] * len(nums)
    left, right = 0, len(nums) - 1

    # Iterate through nums in reveresed order because we place the largest element at the end
    for i, v in reversed(list(enumerate(nums))):
        # Only absolute value matters so place the square of the larger number at the end
        if abs(nums[left]) < abs(nums[right]):
            result[i] = nums[right] * nums[right]
            right -= 1
        else:
            result[i] = nums[left] * nums[left]
            left += 1

    return result


# Time Complexity: O(N)
# Space Complexity: O(N)