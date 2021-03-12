# Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

# Example:

# Input:  [1,2,3,4]
# Output: [24,12,8,6]

# Leetcode 238: https://leetcode.com/problems/product-of-array-except-self/
# Difficulty: Medium

def productExceptSelf(self, nums: List[int]) -> List[int]:
    # Initialize a variable to store the current multiplication and the results list
    multiplier, result = 1, [1] * len(nums)
    # The multiplier keeps track of everything to the left and then right of the current index

    # Loop through forwards
    for i, v in enumerate(nums):

        # Set the ith index to be the multiplier, and multiply the multiplier with the current number
        result[i] *= multiplier
        multiplier *= v

    # Reset multiplier
    multiplier = 1

    # Do the same in reverse
    for i, v in reversed(list(enumerate(nums))):
        result[i] *= multiplier
        multiplier *= v

    return result


# Time Complexity: O(N)
# Space Complexity: O(1) as output array does not count
