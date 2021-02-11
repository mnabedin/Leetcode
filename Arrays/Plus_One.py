# Given a non-empty array of decimal digits representing a non-negative integer, increment one to the integer.

# The digits are stored such that the most significant digit is at the head of the list, and each element in the array contains a single digit.

# You may assume the integer does not contain any leading zero, except the number 0 itself.

# Leetcode 66: https://leetcode.com/problems/plus-one/
# Difficulty: Easy

def plusOne(self, digits: List[int]) -> List[int]:
    i = len(digits) - 1

    # Iterate through the list in reverse order
    while i >= 0:
        # If we ever encounter a number that is not 9, incrememnt it and return the list
        if digits[i] != 9:
            digits[i] += 1
            return digits
        # If we encounter a 9, set that digit to 0
        digits[i] = 0
        i -= 1

    # If we reached this point without returning, the digits list is all zeroes so just add 1 to the start
    return [1] + digits

# Time Complexity: O(N)
# Space Complexity: O(1)
