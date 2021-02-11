# Given a non-empty array of decimal digits representing a non-negative integer, increment one to the integer.

# The digits are stored such that the most significant digit is at the head of the list, and each element in the array contains a single digit.

# You may assume the integer does not contain any leading zero, except the number 0 itself.

# Leetcode 66: https://leetcode.com/problems/plus-one/
# Difficulty: Easy

def plusOne(self, digits: List[int]) -> List[int]:
    i = len(digits) - 1

    while i >= 0:
        if digits[i] != 9:
            digits[i] += 1
            return digits
        digits[i] = 0
        i -= 1

    return [1] + digits

# Time Complexity: O(N)
# Space Complexity: O(1)
