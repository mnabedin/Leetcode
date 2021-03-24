# Given an array of integers nums and an integer k, return the number of unique k-diff pairs in the array.

# A k-diff pair is an integer pair (nums[i], nums[j]), where the following are true:

# 0 <= i, j < nums.length
# i != j
# |nums[i] - nums[j]| == k
# Notice that |val| denotes the absolute value of val.

# Example 1:

# Input: nums = [3,1,4,1,5], k = 2
# Output: 2
# Explanation: There are two 2-diff pairs in the array, (1, 3) and (3, 5).
# Although we have two 1s in the input, we should only return the number of unique pairs.

# Leetcode 532: https://leetcode.com/problems/k-diff-pairs-in-an-array/
# Difficulty: Easy

# Solution: Generate a dictionary containing the frequencies of each element and increment pairs if pair found


def findPairs(self, nums: List[int], k: int) -> int:
    lookingFor = {}
    pairs = 0

    # Populate frequency dictionary where the keys are elements in nums, and values are the frequencies
    for i, v in enumerate(nums):
        lookingFor[v] = lookingFor.get(v, 0) + 1

    # Iterate through the keys
    for i in lookingFor:
        # If k is 0, increment pairs if unique duplicates are found
        if k == 0:
            if lookingFor[i] > 1:
                pairs += 1
        # If k >= 0 then look for (i + k) in dictionary and increment pairs if found
        # Realize (i + k) will take care of (i - k) as well as (i + k)
        else:
            if (i + k) in lookingFor:
                pairs += 1

    return pairs

# Time Complexity: O(N)
# Space Complexity: O(N)
