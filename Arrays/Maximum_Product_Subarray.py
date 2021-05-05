# Given an integer array nums, find a contiguous non-empty subarray within the array that has the largest product,
# and return the product.
# It is guaranteed that the answer will fit in a 32-bit integer.
# A subarray is a contiguous subsequence of the array.

# Example 1:
# Input: nums = [2,3,-2,4]
# Output: 6
# Explanation: [2,3] has the largest product 6.

# Example 2:
# Input: nums = [-2,0,-1]
# Output: 0
# Explanation: The result cannot be 2, because [-2,-1] is not a subarray.

# Leetcode 152: https://leetcode.com/problems/maximum-product-subarray/
# Difficulty: Medium

# Solution: Keep track of both max and min product so far because a negative number can become positive if it's
# multiplied with another negative number

def maxProduct(self, nums: List[int]) -> int:
    # If there is only one element in the list, return it
    if len(nums) == 1:
        return nums[0]

    # Initialize ans, maxProd, minProd
    ans = maxProd = minProd = nums[0]

    # Iterate through list skipping first element
    for num in nums[1:]:
        # We use temp variables x, y for min, max prod before we write over previous min, max prod
        x = max(num, num * maxProd, num * minProd)
        y = min(num, num * maxProd, num * minProd)
        maxProd, minProd = x, y
        ans = max(ans, maxProd)

    return ans

# Time Complexity: O(N)
# Space Complexity: O(1)
