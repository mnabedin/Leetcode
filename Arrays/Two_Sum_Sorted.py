# Given an array of integers numbers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.

# Return the indices of the two numbers (1-indexed) as an integer array answer of size 2, where 1 <= answer[0] < answer[1] <= numbers.length.

# You may assume that each input would have exactly one solution and you may not use the same element twice.

# Example 1:

# Input: numbers = [2,7,11,15], target = 9
# Output: [1,2]
# Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.

# Leetcode 167: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
# Difficulty: Easy

# Solution: Modify left and right pointers based on the size of the target relative to the sum of nums[l] and nums[r]

def twoSum(self, numbers: List[int], target: int) -> List[int]:
    l, r = 0, len(numbers) - 1

    while l < r:
        if numbers[l] + numbers[r] == target:
            return [l + 1, r + 1]
        elif numbers[l] + numbers[r] > target:
            r -= 1
        else:
            l += 1

    return []

# Time Complexity: O(N)
# Space Complexity: O(1)
